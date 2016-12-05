// ConsoleApplication30.cpp : Defines the entry point for the console application.
//// double pointer example
#include "stdafx.h"
#include <iostream>

typedef struct llist {
	void *data;
	llist *next;

}llist;



llist  *testlistptr, *headptr, *iterator;
void add_to_list(char *c_ptr) {

	llist *nodeptr = NULL;

	nodeptr = (llist *)malloc(sizeof(llist));

	nodeptr->data = c_ptr;

	nodeptr->next = NULL;

	testlistptr->next = nodeptr;
};
void create_list(char *c_ptr) {

	testlistptr = (llist *)malloc(sizeof(llist));


	testlistptr->data = c_ptr;
	testlistptr->next = NULL;

	headptr = testlistptr;
};
void print_list() {
	iterator = headptr;
	while (iterator != NULL) {
		std::cout << (char *)iterator->data << std::endl;
		iterator = iterator->next;
	}
};
void delete_list() {
	llist *prevptr;
	while (headptr != NULL) {
		prevptr = headptr;
		headptr = headptr->next;
		free(prevptr);
	}

};
void delete_element(char *ptr_to_find) {
	llist *prevptr;
	iterator = headptr;
	while (iterator != NULL) {

		if (!strcmp((char *)iterator->next->data, ptr_to_find)) {
			prevptr = iterator->next;
			if (iterator->next->next != NULL)
				iterator = iterator->next->next;
			else {
				iterator->next = NULL;
				return;
			}
			free(prevptr);

		}
		else
			iterator = iterator->next;

	}
	return;
};


int main()
{

	 

	char *test1 = "this is a test";

	create_list(test1);

	add_to_list("test 2");

	print_list();
	std::cout << "before delete element" << std::endl;
	delete_element("test 2");
	print_list();
	std::cout << "after delete element" << std::endl;


	delete_list();

	std::cout << "after delete" << std::endl;
	create_list(test1);
	add_to_list("test 3");
	print_list();



	return 0;
}

