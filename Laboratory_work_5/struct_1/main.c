#include <stdio.h>
struct student {
	char* name;
	int location;
	int mark;
};
#define SIZE 4
int main() {

	struct student* students_ptrs[SIZE];	
	struct student students[SIZE];

	students[0].name = "Basha";
	students[0].mark = 9;
	students[0].location = 1;


	students[1].name = "Cleg";
	students[1].mark = 9;
	students[1].location = 1;


	students[2].name = "Ilya";
	students[2].mark = 8;
	students[2].location = 0;


	students[3].name = "Aikita";
	students[3].mark = 10;
	students[3].location = 1;

	for (size_t i = 0; i < SIZE; i++)
	{
		printf("%s \n", students[i].name);
		printf("%d \n", students[i].mark);
		printf("%d \n", students[i].location);


	}

	for (size_t i = 0; i < SIZE; i++)
	{
		students_ptrs[i] = &students[i];
	}


	// Сортировка массива пузырьком
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = 0; j < SIZE - i - 1; j++) {
			if (strcmp(students_ptrs[j]->name, students_ptrs[j + 1]->name) > 0) {
				// меняем элементы местами
				struct student* temp = students_ptrs[j];
				students_ptrs[j] = students_ptrs[j + 1];
				students_ptrs[j + 1] = temp;
			}
		}
	}

	printf("Names: \n");
	for (size_t i = 0; i < SIZE; i++)
	{
		if (students_ptrs[i]->mark >= 9 && students_ptrs[i]->location) {
			printf("%s \n", students_ptrs[i]->name);
			printf("%d \n", students_ptrs[i]->mark);
			printf("%d \n", students_ptrs[i]->location);
		}

	}

	return 0;
}