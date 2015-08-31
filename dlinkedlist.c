// James Murphy
// CPSC 405-02
// Lab #1 - C linked list

#include <stdlib.h>
#include <malloc.h>

struct ll {
	int data;
	
	struct ll * prev;
	struct ll * next;
};


int add_node(struct ll **list, int y) {
	struct ll * nextptr;
	struct ll * prevptr;
	struct ll * currptr;
//	printf("Constructed pointer variables.\n");
		
	struct ll * newptr = (struct ll *) malloc(sizeof(struct ll));
	if (newptr == NULL) {
		return 0;
	}
//	printf("Successfully created a new node.\n");
	newptr->data = y;
	newptr->next = NULL;
	
	currptr = *list;
	prevptr = NULL;
	
	// this is the start of the list
//	printf("Starting add procedure.\n");
	if (currptr == NULL) { 
//		printf("Adding to empty list.\n");
		*list = newptr;
		return 1;
	} else {
		if (currptr->data >= y) {
//			printf("Adding underneath list.\n");
			newptr->prev = NULL;
			newptr->next = currptr;
			currptr->prev = newptr;
			*list = newptr;
			return 1;
		} else if ((currptr->data < y) && (currptr->next == NULL)) {
//			printf("Adding onto singleton list.\n");
			currptr->next = newptr;
			newptr->prev = currptr;
			return 1;
		} else {
//			printf("General add case.\n");
			while (currptr->next != NULL) {
				if (currptr->data < y) {
					struct ll * temp;
					temp = currptr->next;
					currptr->next = newptr;
					newptr->prev = currptr;
					newptr->next = temp;
					return 1;
				}
			}
		}
	}
//	printf("node was created, list was not expanded.\n");
	return -1; // list was not expanded ==> logic incomplete
}

void remove_node(struct ll **list, int z) {
	struct ll * prevnode;
	struct ll * currnode;
	struct ll * temp;
	
	if ((*list)->data == z) {
		temp = *list;
		*list = (*list)->next;
		free(temp);
		return;
	} else {
		prevnode = (*list);
		currnode = (*list)->next;
		
		while ((currnode->data != z) && (currnode->next != NULL)) {
			prevnode = currnode;
			currnode = currnode->next;
		}
		
		if (currnode->data == z) {
			temp = currnode;
			prevnode->next = currnode->next;
			if (currnode->next != NULL) {
				currnode->next->prev = prevnode;
			}
			free(temp);
			return;
		}
	}
	return;
}

void print_list(struct ll * list) {
	struct ll * currnode;
	while (currnode->next != NULL) {
		printf("%d\n", currnode->data);
		currnode = currnode->next;
	}
	printf("%d\n\n", currnode->data);
	
	return;
}
