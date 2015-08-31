#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

	struct dlinkedlist * test = 0;
//	printf("Begin adding nodes.\n");
	add_node(&test, 10);
//	printf("First node added.\n");
	add_node(&test, 8);
	add_node(&test, 8);
	add_node(&test, 11);
	add_node(&test, 9);
//	printf("Finished adding nodes.\n");
	print_list(test);
	
//	printf("Attempt to remove node with data = 11.\n");
	remove_node(&test, 11);
	
	print_list(test);
//	printf("Attempt to remove node with data = 9.\n");
	remove_node(&test, 9);
//	printf("Test actions complete.\n");	
	print_list(test);
	
	return 0;
}
	
