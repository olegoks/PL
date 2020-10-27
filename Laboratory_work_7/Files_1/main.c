#include <stdio.h>
#include <locale.h>
struct employee {

	char name[20];
	char department[20];
	unsigned int salary;

};

typedef unsigned long int FileSize;

unsigned long int ReturnFileSize(FILE*const file_stream) {

	typedef unsigned long int FilePtr;

	const FilePtr old_position = ftell(file_stream);
	fseek(file_stream, 0, SEEK_END);
	const FileSize size_bytes = ftell(file_stream);
	fseek(file_stream, 0, old_position);

	return size_bytes;
}

int ReadDataBase(FILE* const file_stream, struct employee** employers_ptr) {

	typedef unsigned long int size_t;

	const FileSize db_size = ReturnFileSize(file_stream);
	const size_t element_size = sizeof(struct employee);
	if (db_size % element_size != 0) return -1;

	const unsigned int number_of_elements = db_size / element_size;

	if (*employers_ptr != NULL)free(*employers_ptr);
	*employers_ptr = (struct employee*) malloc(db_size);
	const size_t read_number_elements = fread(*employers_ptr, element_size, number_of_elements, file_stream);
	
	if (read_number_elements != number_of_elements) {
		free(*employers_ptr);
		return -1;
	}

	return number_of_elements;
}

void DeleteElement(struct employee** Array, const int index, const int array_size) {

	struct employee* new_array_ptr = malloc(sizeof(struct employee) * array_size - 1);

	int kk_valya = 0;

	for (int i = 0; i < array_size - 1; i++)
	{
		if (i == index)kk_valya = 1;
		new_array_ptr[i] = (*Array)[i + kk_valya];

	}

	free(*Array);
	*Array = new_array_ptr;

}

void DeleteEmployee(const char* const employee_name, struct employee** employers, unsigned int* number_of_elements) {
	
	int names_are_equal = 0, end = 0;
	int index = 0;

	while(!names_are_equal && !end){

		names_are_equal = !strcmp((*employers)[index].name, employee_name);
		end = !(index < *number_of_elements);
		if (names_are_equal) {

			DeleteElement(employers, index, *number_of_elements);

		}

		index++;

	}

	(*number_of_elements)--;
}
void AddEmployee(const struct employee* const element, struct employee** employers, unsigned long int* number_of_elements) {

	struct employee* new_employers_ptr = malloc((*number_of_elements + 1) * sizeof(struct employee));

	for (size_t i = 0; i < *number_of_elements; i++)
	{
		new_employers_ptr[i] = (*employers)[i];
	}

	if (*employers != NULL) free(*employers);

	const unsigned long last_index = *number_of_elements;
	new_employers_ptr[last_index] = *element;
	*employers = new_employers_ptr;
	(*number_of_elements)++;
}

enum Command {
	SALARY_SUM_AND_AVERAGE_SALARY = 1,
	ADD,
	DELETE,
	EDIT,
	SHOW,
	EXIT,
	NOTHING
};
void PrintMenu() {
	printf("1. Вывести общую сумму выплат за месяц по отделу и средний заработок сотрудника.\n2. Добавить сотрудника.\n3. Удалить сотрудника.\n4. Изменить данные сотрудника.\n5. Вывести список.\n6. Выход.\n");
}
enum Command ReadCommand() {

	int command_id;
	scanf_s("%d", &command_id); fflush(stdin);
	return (enum Command) command_id;

}
void ProcessCommand(enum Command command, struct employee** employers, unsigned int* number_of_elements, FILE* const database) {

	switch (command) {
	case ADD: {

		struct employee new_employee;
		printf("Введите данные:\n");
		printf("Имя сотрудника: ");
		fflush(stdin);
		scanf_s("%s", &new_employee.name, 20);
		fflush(stdin);
		printf("Отдел: ");
		scanf_s("%s", new_employee.department, 20);
		printf("Зарплата: ");
		scanf_s("%d", &new_employee.salary);
		AddEmployee(&new_employee, employers, number_of_elements);
		break;
	}
	case DELETE: {
		char delete_employee[20];
		printf("Введите имя сотрудника: ");
		scanf_s("%s", delete_employee, 20);
		DeleteEmployee(delete_employee, employers, number_of_elements);

		break;
	}

	case EDIT: {

		char edit_employee[20];
		printf("Введите имя сотрудника: ");
		scanf_s("%s", edit_employee, 20);

		struct employee* current_employee = NULL;

		int names_are_equal = 0, end = 0;
		int index = 0;

		while (!names_are_equal && !end) {

			names_are_equal = !strcmp((*employers)[index].name, edit_employee);
			end = !(index < *number_of_elements);
			if (names_are_equal) {

				current_employee = &(*employers)[index];

			}

			index++;

		}

		if (current_employee != NULL) {

			printf("Имя сотрудника: %s \n", current_employee->name);
			printf("Отдел: %s \n", current_employee->department);
			printf("Зарплата: %d \n\n", current_employee->salary);
			fflush(stdout);

			struct employee new_employee;
			printf("Введите данные:\n");
			printf("Имя сотрудника: ");
			fflush(stdin);
			scanf_s("%s", &new_employee.name, 20);
			fflush(stdin);
			printf("Отдел: ");
			scanf_s("%s", new_employee.department, 20);
			printf("Зарплата: ");
			scanf_s("%d", &new_employee.salary);

			*current_employee = new_employee;

		}

		break;
	}
	case SALARY_SUM_AND_AVERAGE_SALARY: {

		char department[20];
		printf("Введите номер отдела:");
		scanf_s("%s", department, 20);
		fflush(stdin);

		unsigned int sum = 0;
		unsigned int employers_in_department = 0;
		for (size_t i = 0; i < *number_of_elements; i++)
		{
			struct employee current_employee = (*employers)[i];
			int department_found = !strcmp(current_employee.department, department);
			
			if (department_found) {

				sum += current_employee.salary;
				employers_in_department++;

			}

			
		}
		if (employers_in_department == 0) printf("Нет такого отдела.\n");
		else {
			printf("Общая сумма выплат: %d.\n", sum);
			printf("Средмесячный заработок сотрудника: %d.\n", (sum / employers_in_department));
		}
		system("pause");
		break;
	}

	case SHOW: {

		for (size_t i = 0; i < *number_of_elements; i++)
		{

			struct employee current_employee = (*employers)[i];
			printf("Имя сотрудника: %s \n", current_employee.name);
			printf("Отдел: %s \n", current_employee.department);
			printf("Зарплата: %d \n\n", current_employee.salary);
			fflush(stdout);
			
		}

		system("pause");
		break;
	}
	case EXIT: {

		fseek(database, 0, SEEK_SET);

		fclose(database);

		FILE* file;
		errno_t error = fopen_s(&file, "text.txt", "w");
		if (!error) fwrite(*employers, sizeof(struct employee), *number_of_elements, file);

		fclose(file);

		break;
	}
	}

}

int main() {

	FILE* database;
	const errno_t f_open_error = fopen_s(&database, "text.txt", "ab+");
	setlocale(LC_ALL, "ru");
	struct employee* employers = NULL;
	unsigned int number_of_elements = ReadDataBase(database, &employers);
	enum Command command = NOTHING;

	while (command != EXIT) {

		PrintMenu();
		command = ReadCommand();
		ProcessCommand(command, &employers, &number_of_elements, database);
		system("cls");
	}
	    
	return 0;
}