#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {

	struct dlinkedlist * test = 0;
	add_node(&test, 10);
	add_node(&test, 8);
	add_node(&test, 8);
	add_node(&test, 11);
	add_node(&test, 9);
	print_list(test);
	
	remove_node(&test, 11);
	
	print_list(test);
	remove_node(&test, 9);
	print_list(test);
	
	return 0;
}
	
