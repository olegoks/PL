//пример использования функции fgets

#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LEN 28

struct student {

	char name[30];
	float mark;

};

int main() {

	FILE* ptr_file;
	fopen_s(&ptr_file, "F1.txt", "r");
	char number_str[10];

	if (!ptr_file) return 1;

	FILE* ptr_new_file;

	fopen_s(&ptr_new_file, "F2.txt", "w");

	while (!feof(ptr_file)) {

		fgets(number_str, 8, ptr_file);
		int number_int = atoi(number_str); 

		if (number_int % 2 == 1) {

			fputs(number_str, ptr_new_file);

		}

	}

	fclose(ptr_file);

	return 0;
}