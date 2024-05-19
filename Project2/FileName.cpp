#include <iostream>
#include <cstring>
#pragma warning(disable : 4996) 
using namespace std;
/*Дано два текстові файли. З'ясувати, чи збігаються їхні рядки.
Якщо ні, то вивести рядок, який не збігається, з кожного файлу.*/
/*int main()
{
	const char* PATH_TO_FILE1 = "data.txt";
	const char* PATH_TO_FILE2 = "data1.txt";
	FILE* file1 = fopen(PATH_TO_FILE1, "r");
	FILE* file2 = fopen(PATH_TO_FILE2, "r");
	const int MAX_LINE_LENGTH = 555;
	char line1[MAX_LINE_LENGTH];
	char line2[MAX_LINE_LENGTH];
	bool filesMatch = true;

	while (fgets(line1, MAX_LINE_LENGTH, file1) && fgets(line2, MAX_LINE_LENGTH, file2))
	{
		for (int i = 0; line1[i] != '\0'; ++i)
		{
			if (line1[i] == '\r' || line1[i] == '\n')
			{
				line1[i] = '\0';
				break;
			}
		}
		for (int i = 0; line2[i] != '\0'; ++i)
		{
			if (line2[i] == '\r' || line2[i] == '\n')
			{
				line2[i] = '\0';
				break;
			}
		}

		if (strcmp(line1, line2) != 0)
		{
			filesMatch = false;
			cout << "Mismatch found:" << endl;
			cout << "File 1: " << line1 << endl;
			cout << "File 2: " << line2 << endl;
		}

	}
	if (!feof(file1) || !feof(file2))
	{
		filesMatch = false;
		if (!feof(file1))
		{
			cout << "File 1:" << endl;
			while (fgets(line1, MAX_LINE_LENGTH, file1))
			{
				cout << line1 << endl;
			}
		}
		if (!feof(file2))
		{
			cout << "File 2:" << endl;
			while (fgets(line2, MAX_LINE_LENGTH, file2))
			{
				cout << line2 << endl;
			}
		}
		if (filesMatch)
		{
			cout << "Files match." << endl;
		}

		fclose(file1);
		fclose(file2);
	}
	else
	{
		cout << "Error";
		if (file1 == nullptr) fclose(file1);
		if (file2 == nullptr) fclose(file2);
	}
}*/
/*Дан текстовий файл. Необхідно створити
новий файл і записати в нього таку статистику по вихідному файлу:
■ Кількість символів;
■ Кількість рядків;
■ Кількість голосних;
■ Кількість приголосних;
■ Кількість цифр*/
bool isVowel(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool isConsonant(char c)
{
	return (c >= 'a' && c <= 'z' && !isVowel(c)) || (c >= 'A' && c <= 'Z' && !isVowel(c));
}

int main()
{
	const char* inputFilePath = "input.txt";
	const char* outputFilePath = "output.txt";

	FILE* inputFile = fopen(inputFilePath, "r");
	FILE* outputFile = fopen(outputFilePath, "w");

	if (inputFile == nullptr)
	{
		cout << "Error opening the input file." << endl;
	}
	if (outputFile == nullptr)
	{
		cout << "Error opening the output file." << endl;
		fclose(inputFile);
	}

	int charCount = 0;
	int lineCount = 0;
	int vowelCount = 0;
	int consonantCount = 0;
	int digitCount = 0;

	char c;
	while (!feof(inputFile))
	{
		c = fgetc(inputFile);

		charCount++;

		if (c == '\n')
		{
			lineCount++;
		}

		if (c >= '0' && c <= '9')
		{
			digitCount++;
		}
		else if (isVowel(c))
		{
			vowelCount++;
		}
		else if (isConsonant(c))
		{
			consonantCount++;
		}
	}

	fprintf(outputFile, "Number of characters: %d\n", charCount);
	fprintf(outputFile, "Number of lines: %d\n", lineCount);
	fprintf(outputFile, "Number of vowels: %d\n", vowelCount);
	fprintf(outputFile, "Number of consonants: %d\n", consonantCount);
	fprintf(outputFile, "Number of digits: %d\n", digitCount);

	fclose(inputFile);
	fclose(outputFile);

	return 0;
}