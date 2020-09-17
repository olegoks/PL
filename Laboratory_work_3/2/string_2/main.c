#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 100
char glasnaya(char symbol) {

	char glasnii[6] = {'a','e','y','u','i','o'};

	for (int i = 0; i < 6; i++)
	{
		if (symbol == glasnii[i]) return 1;

	}

	return 0;
}

int main() {
	typedef unsigned int uint;
	char string[SIZE];
	for (uint i = 0; i < SIZE; i++)string[i] = 0;
	gets(string);
	uint number = 0;
	for (uint i = 0; i < SIZE; i++)
	{
		if (glasnaya(string[i])) number++;
	}
	printf("%d", number);
	system("pause");
	return 0;
}