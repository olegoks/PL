#include "forward_list.h"
#include <iostream>

void push(lst::forward_list<int>& list, int value) {
	
	bool is_insert = false;

	for (size_t index = 0; index < list.size(); index++) {

		if (list[index] > value) {

			list.insert(index, value);
			is_insert = true;
			break;
		}

		}
	if (!is_insert)
	list.push_back(value);
}

void print(const lst::forward_list<int>& list){
	for (size_t i = 0; i < list.size(); i++){

		std:: cout << list[i] << std::endl;

	}
}

int main(){

	lst::forward_list<int> list;

	push(list, 1);
	push(list, 4);
	push(list, 3);
	push(list, 5);
	push(list, 3);

	int list_size = list.size();
	for (size_t index= 0; index < list_size; index++){

		std::cout << list[index] << std::endl;

	}

	bool input = true;
	while (input) {

		int input_int;
		
		std::cout << "print value:" << std::endl;
		std::cin >> input_int;
		system("cls");
		if (input_int == 0)input = false;
		else {
			push(list, input_int);
			print(list);
		}
		
	}

	return 0;
}