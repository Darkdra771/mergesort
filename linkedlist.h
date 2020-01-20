#pragma once
#ifndef LINKEDLIST_H
#define  LINKEDLIST_H

class LinkedList{

	private:

		int value;
		LinkedList* next;

	public:

		LinkedList(){
			value = 0;
			next = NULL;
		}

		LinkedList(const int& val, LinkedList* n){
			value = val;
			next = n;
		}

		void setVal(const int& val) {
			value = val;
		}
	
		void setNext(LinkedList* n) {
			next = n;
		}

		void print() {
			std::cout << this->value << " ";

			LinkedList* temp = this;

			while (temp->next != NULL) {
				temp = temp->next;
				std::cout << temp->value << " ";
			}

			std::cout << std::endl;
		}

		static void splitList(LinkedList* head, LinkedList** list1, LinkedList** list2) {
			//using fast and slow pointers to split the list
			LinkedList* slow = head;
			LinkedList* fast = head->next;


			while (fast != NULL) {
				fast = fast->next;
				if (fast != NULL) {
					fast = fast->next;
					slow = slow->next;
				}
			}

			*list1 = head;
			*list2 = slow->next;

			slow->next = NULL;

		}

		static LinkedList* merge(LinkedList* list1, LinkedList* list2) {
			//check base case
			if (list1 == NULL) {
				return list2;
			}
			else if (list2 == NULL) {
				return list1;
			}
			
			LinkedList* result = NULL;

			if (list1->value <= list2->value) {
				result = list1;
				result->next = merge(list1->next, list2);
			}
			else {
				result = list2;
				result->next = merge(list1, list2->next);
			}


			return result;
		}

		//implement merge sort
		static LinkedList* mergeSort(LinkedList* head) {
			if (head == NULL || head->next == NULL) {
				return head;
			}

			LinkedList* list1 = NULL;
			LinkedList* list2 = NULL;

			splitList(head, &list1, &list2);

			list1 = mergeSort(list1);
			list2 = mergeSort(list2);
			
			return merge(list1,list2);
		
		}

};

#endif
