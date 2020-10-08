//пример использования функции fgets

#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LEN 28
#define NUM_STUDENTS 3

struct student {

	char group[30];
	char name[30];
	int marks[5];

};

int main() {

	FILE* ptr_file;
	errno_t error = fopen_s(&ptr_file, "test_1.txt", "r");
	char mystring[100];
	struct student students[3] = { 0 };

	if (!ptr_file) return 1;
	unsigned int index = 0;
	while (!feof(ptr_file)) {

		if (fgets(students[index].group, MAX_LINE_LEN, ptr_file) != NULL) {

			puts(students[index].group);

		}

		if (fgets(students[index].name, MAX_LINE_LEN, ptr_file) != NULL) {

			puts(students[index].name);

		}

		for (size_t i = 0; i < 5; i++)
		{

			if (fgets(mystring, MAX_LINE_LEN, ptr_file) != NULL) {

				students[index].marks[i] = atoi(mystring);
				printf("%d \n", students[index].marks[i]);

			}

		}
		

		index++;

	}
	fclose(ptr_file);

	FILE* ptr_new_file;
	fopen_s(&ptr_new_file, "out.txt", "a+");

	for (size_t i = 0; i < NUM_STUDENTS; i++)
	{
		const int num_marks = 5;
		float sum = 0;
		
		for (size_t j = 0; j < num_marks; j++)
		{
			sum += (float)students[i].marks[j];
		}
		
		if (sum / num_marks > 8.0f) {
			
			int result = fputs(students[i].name, ptr_new_file); // и записываем ее в файл
			if (!result) // если запись произошла успешно
				printf("Строка в файл успешно записана! \n"); // выводим сообщение

		}

	}

	// float atof(char *);


	return 0;
}