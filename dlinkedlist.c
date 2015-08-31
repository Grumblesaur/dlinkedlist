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
	struct ll * currptr, * temp;
//	printf("Constructed pointer variables.\n");
		
	struct ll * newptr = (struct ll *) malloc(sizeof(struct ll));
	if (newptr == NULL) {
		return 0;
	}
//	printf("Successfully created a new node.\n");
	newptr->data = y;
	newptr->next = NULL;
	
	currptr = *list;
	//list is empty
	if (*list == NULL) {
		*list = newptr;
		return 1;
	}
	//list is non-empty
	newptr->prev = NULL;
	newptr->next = currptr;
	*list = newptr;
	
	return 1;
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
	}
	prevnode = (*list);
	currnode = (*list)->next;
	
	while (currnode->data != z) {
		if (currnode->next == NULL) {
			return;
		}
		prevnode = currnode;
		currnode = currnode->next;
	}
	
	temp = currnode;
	prevnode->next = currnode->next;
	currnode->next->prev = prevnode;
	
	free(temp);
	
	return;
}

void print_list(struct ll * list) {
	struct ll * currnode = list;
	if (list == NULL) {
		printf("List is empty!\n");
		return;
	}
	while (currnode->next != NULL) {
		printf("%d\n", currnode->data);
		currnode = currnode->next;
	}
	printf("%d\n\n", currnode->data);
	
	return;
}
