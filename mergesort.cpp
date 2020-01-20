#include <iostream>
#include "linkedlist.h"

int main(int argc, char* argv[]){

	LinkedList* head = new LinkedList(10, NULL);
	LinkedList* n = head;

	int list[10] = { 8, 1, 7, 3, 5, 2, 9, 0, 4, 6 };

	//create the linkedlist
	for (int i = 0; i < 10; ++i) {
		LinkedList* next = new LinkedList(list[i], NULL);
		head->setNext(next);
		head = next;
	}

	std::cout << "Before: ";
	n->print();

	LinkedList* sorted = LinkedList::mergeSort(n);

	std::cout << "After merge sort: ";
	sorted->print();

	return 0;

}
