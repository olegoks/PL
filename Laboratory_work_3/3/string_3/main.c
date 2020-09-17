#include <stdio.h>
#include <conio.h>
#include <string.h>
#define SIZE 100

int main() {

	typedef unsigned int uint;
	char string[SIZE];
	for (uint i = 0; i < SIZE; i++)string[i] = 0;
	gets(string);


	uint index_end;
	uint index = SIZE - 1;

	while (string[index] == 0) index--;
	index_end = index;

	for (uint i = 0; i < SIZE; i++)
	{

		if (string[i] == ' ') string[i + 1] -= 32;

	}
	string[0] -= 32;
	for (uint i = 0; i < SIZE; i++)
	{
		printf("%c", string[i]);
	}

	return 0;
}