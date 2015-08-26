// James Murphy
// CPSC 405-02
// Lab #1 - C linked list

#include <stdlib.h>
#include <malloc.h>

struct Node {
	struct Node * prev;
	struct Node * next;
	int data;
};

struct DLinkedList {
	struct Node * head;
};

struct Node * add_node(struct DLinkedList * dll, int value) {
	struct Node * temp = (struct Node *) malloc(sizeof(struct Node));
	temp->data = value;

	// attach node to front of list when empty
	if (dll->head == NULL) {
		dll->head = temp;
		dll->head->data = value;
		dll->head->prev = NULL;
		return temp;
	}
	
	// cover edge case where value is less than first in line
	struct Node * curr = dll->head;
	if (curr->data > value) {
		// make it first in line
		dll->head = temp;
		// reassign pointers
		temp->next = curr;
		curr->prev = temp;
		temp->prev = NULL;
		return temp;
	}
	
	while (curr->next != NULL) {
		if (value <= curr->data) {
			curr->prev->next = temp;
			temp->prev = curr->prev;
			curr->prev = temp;
			temp->next = curr;
		}
		curr = curr->next;
	}
	
	if (curr->next == NULL && value > curr->data) {
		curr->next = temp;
		temp->prev = curr;
		temp->next = NULL;
	}

	return temp;
	
}



