#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
bool isVowel(char i);
int toPigLatin(char word[50]);
int checkCapitalLetters(char word[50]);

int main()
{
	char myWord[50];
	char answer = 'N';
	int errorType = 0;
	int i = 0;

	cout << " Welcome to Parker's English to PigLatin word translator!!" << endl;
	cout << " This Program allows you to enter any English word that   " << endl;
	cout << " you wish to be translated, and returns it in pig latin.  " << endl;
	cout << " Words may be up to 50 characters in length, must begin with" << endl;
	cout << " a letter, and may only have the 1st letter capitalized." << endl;
	cout << " Now what are you waiting for!? Enter a word to begin translating!\n\n" << endl;


	do
	{
		cout << "Enter the Word to be translated to PigLatin: ";
		cin >> myWord;

		errorType = toPigLatin(myWord);//errorType determines what gets output to the console
		if (errorType == 0)
			cout << "Your word in PigLatin is: " << myWord << endl;
		else if (errorType == 1)
			cout << "Error: Your word must not begin with a number" << endl;
		else if (errorType == 2)
			cout << "Error: Too many Capital Letters" << endl;
		else if (errorType == 3)
			cout << "Error: Only the 1st Letter may be capitalized" << endl;


		cout << "Would you like to translate another word? Enter Y to continue:  ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (answer == 'y' || answer == 'Y');
}

bool isVowel(char b) //Checks whether first letter is a vowel
{
	if ((b == 'a') || (b == 'e') || (b == 'i') || (b == 'o') || (b == 'u') ||
		(b == 'A') || (b == 'E') || (b == 'I') || (b == 'O') || (b == 'U'))
	{
		return true;
	}
	else
		return false;
}

int checkCapitalLetters(char word[50])//to deal with case sensitivity this checks that only 1st letter is capitalized
{
	int i;
	int checkPosition = 0;
	int count = 0;
	int j = strlen(word) - 1;
	for (i = 0; i < j; i++)
	{
		if (word[i] == 'A' || word[i] == 'B' || word[i] == 'C' || word[i] == 'D' || word[i] == 'E' ||
			word[i] == 'F' || word[i] == 'G' || word[i] == 'H' || word[i] == 'I' || word[i] == 'J' ||
			word[i] == 'K' || word[i] == 'L' || word[i] == 'M' || word[i] == 'N' || word[i] == 'O' ||
			word[i] == 'P' || word[i] == 'Q' || word[i] == 'R' || word[i] == 'S' || word[i] == 'T' ||
			word[i] == 'U' || word[i] == 'V' || word[i] == 'W' || word[i] == 'X' || word[i] == 'Y' ||
			word[i] == 'Z')
		{
			count++;
			checkPosition = i;
		}
	}

	if (count > 1)
	{
		//errorType = -1
		//cout << "Error: Too many Capital Letters" << endl;
		return 2;
	}
	else if (count == 1 && checkPosition != 0)//makes sure if there is 1 capital letter that its the 1st letter
		return 3;
	//else if (count == 1 && checkPosition == 0)
	return 0;

}
int toPigLatin(char word[50]) //will translate user input to pigLatin, returns value corresponding to errortype
{
	char c = word[0];
	char temp;
	//char tempString[50];

	if (isdigit(word[0]) != 0)//checks 1st character is not a digit
		return 1;
	else if (checkCapitalLetters(word) == 2) //checks that there is atmost 1 capital letter
		return 2;
	else if (checkCapitalLetters(word) == 3)// checks that if there is a capital letter, it's the first
		return 3;
	else if (checkCapitalLetters(word) == 0)//translates to pig latin if all conditions met
	{
		if (strlen(word) <= 2)//words 2 characters in length or less don't need translating
			return 0;
		else if (strcmp(word, "and") == 0 || strcmp(word, "but") == 0 || strcmp(word, "for") == 0 ||
			strcmp(word, "nor") == 0 || strcmp(word, "yet") == 0 || strcmp(word, "And") == 0 ||
			strcmp(word, "But") == 0 || strcmp(word, "For") == 0 || strcmp(word, "Nor") == 0
			|| strcmp(word, "Yet") == 0)
			return 0;
		else if ((isVowel(c) == true) && (strlen(word) > 2))//for words that start with vowels
		{
			strcat(word, "ay\0");
			return 0;
		}

		else if ((isVowel(c) == false) && (strlen(word) > 2))//for words that start with consonants
		{
			int i;
			int j = strlen(word) - 1;
			int count = 0;
			char tempString2[4];

			tempString2[0] = word[0]; //stores first letter of the word
			tempString2[1] = 'a';
			tempString2[2] = 'y';
			tempString2[3] = '\0';
			for (i = 1; i < j + 2; i++)
			{
				temp = word[i];
				word[i - 1] = temp;
				count++;
			}
			strcat(word, tempString2);

			//cout << "word: " << word << endl;

			//cout << "Your word in PigLatin is: " << word << endl;
			return 0;
		}
	}
	return 0;
}
