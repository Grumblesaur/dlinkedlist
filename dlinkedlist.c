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
	struct ll * currptr, * prevptr;
	// create new node; error check	
	struct ll * newptr = (struct ll *) malloc(sizeof(struct ll));
	if (newptr == NULL) {
		return 0;
	}
	newptr->data = y;
	newptr->next = NULL;
	
	currptr = *list;
	//list is empty
	if (*list == NULL) {
		*list = newptr;
		return 1;
	}
	// if new node's data should come before the current first-in-line	
	if (y < currptr->data) {
		newptr->next = currptr;
		currptr->prev = newptr;
		*list = newptr;
		return 1;
	}
	
	prevptr = NULL;
	// anywhere else-case	
	while (y >= currptr->data) {
		if (currptr->next == NULL) {
			currptr->next = newptr;
			newptr->prev = currptr;
			return 1;
		}
		prevptr = currptr;
		currptr = currptr->next;
	}
	
	prevptr->next = newptr;
	newptr->prev = prevptr;
	newptr->next = currptr;
	currptr->prev = currptr;
	return 1;
}

void remove_node(struct ll **list, int z) {
	struct ll * prevnode;
	struct ll * currnode;
	struct ll * temp;
	// value is first in line
	if ((*list)->data == z) {
		temp = *list;
		*list = (*list)->next;
		free(temp);
		return;
	}
	
	// locate node if elsewhere
	prevnode = (*list);
	currnode = (*list)->next;
	while (currnode->data != z) {
		if (currnode->next == NULL) {
			return;
		}
		prevnode = currnode;
		currnode = currnode->next;
	}
	
	// remove it, stitch the list together, and free memory
	temp = currnode;
	struct ll * nextnode = currnode->next;
	if (nextnode == NULL) {
		prevnode->next = NULL;
		return;
	} else {
		prevnode->next = nextnode;
		nextnode->prev = prevnode;
	}
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
