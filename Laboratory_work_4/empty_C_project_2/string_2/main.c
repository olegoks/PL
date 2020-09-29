#include <stdio.h>
#include <locale.h>
#include <memory.h>

void FindWord(char* stroka, unsigned int word_number ) {

	unsigned int counter = 1;
	unsigned int index = 0;

	while (counter != word_number) {

		if (stroka[index] == '_') {
			counter++;
		}

		index++;

	}

	while ((stroka[index] != '_') && (stroka[index] != '\0')) {

		printf("%c", stroka[index]);
		index++;

	}
		
	
}

int main() {

	setlocale(LC_ALL, "ru");
	const char* const base = {"Ñ_ÄÈ×ÜŞ_ß_ÏÎËÀÃÀŞ_ÃËÀÂÀ_ÏĞÅÄÏĞÈßÒÈß_ÏÎ_ÑÂÅÄÅÍÈßÌ_Î_ÌÓÕÎÁÎÉÊÀÕ_ÔÀÇÀÍÜÈÕ_ÊÓĞÎ×ÅÊ"};
	char sentence[100];
	memset(sentence, 0, sizeof(char) * 100);
	gets(sentence);
	char symbol = 'A';
	unsigned int index = 0;
	unsigned int counter = 1;
	while (symbol != '\0') {

		if (symbol == '_') counter++;
		index++;
		symbol = sentence[index];
	}

	unsigned int base_index = 1;
	unsigned int sentence_index = 1;

	for (size_t i = 0; i < counter; i++)
	{
		FindWord(base,base_index );
		printf("_");
		base_index++;
		FindWord(base, base_index);
		base_index++;
		printf("_");
		FindWord(sentence, sentence_index);
		sentence_index++;
		if(!(i == counter - 1))printf("_");


	}

	return 0;
}