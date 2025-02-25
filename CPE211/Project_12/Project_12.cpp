#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef char alphabet[26];
typedef string list[213];
typedef char charList[10];

void arrayStartup(ifstream&, alphabet&, list&);
int letterOrWordCheck();
char letGuess();									// Function Prototypes for the 
string wordGuessed(); 								// program.
int checkLetters(char&, string&, charList&);
int checkWord(string&, string&);
void printWord(string&, charList&);

int main()
{
	ifstream in;
	alphabet letters;
	list wordList;
	int randomNumber, iterable, letterOrWord, letCheck, wordCheck;
	string chosenWord, wordGuess;
	char letterGuess;
	charList correctLetters;
	
	arrayStartup(in, letters, wordList);
	
	cout << string(47, '*') << endl;
	cout << string(19, '*') << " Hangman " << string(19, '*') << endl;
	cout << string(47, '*') << endl << endl;
	cout << "You Start with 5 lives." << endl << endl;
	
	srand(time(0));
	randomNumber = (rand() % 212) + 1;
	chosenWord = wordList[randomNumber];
	cout << chosenWord << endl << endl;
	
	for (int i = 1; i < chosenWord.length(); i++)
	{
		cout << "*";
	}
	cout << endl;
	for (int i = 1; i < chosenWord.length(); i++)
	{
		cout << "-";
	}	
	cout << endl << endl;
	
	iterable = 0;
	while (iterable < 5)
	{
		letterOrWord = letterOrWordCheck();
		if (letterOrWord == 0)
		{
			letterGuess = letGuess();
			letCheck = checkLetters(letterGuess, chosenWord, correctLetters);
			if (letCheck == 0)
			{
				iterable++;
				cout << "That letter is not in the word! You lost a life!\nCurrent life total is: " << (5-iterable) << endl << endl; 
			} 
			else if (letCheck == 1)
			{
				cout << "That letter was correct! Time to guess again!\nCurrent life total is: " << (5-iterable) << endl << endl;
			}
		}
		else if (letterOrWord == 1)
		{
			wordGuess = wordGuessed();
			wordCheck = checkWord(wordGuess, chosenWord);
			if (wordCheck == 0)
			{
				cout << "Sorry, your guess was wrong!\nThe correct word was: " << chosenWord << endl;
				cout << "Play again sometime!" << endl << endl;
				return 0;
			}
			else if (wordCheck == 1)
			{
				cout << "Congrats! You guessed the word correctly!\nThe correct word was: " << chosenWord << endl;
				cout << "Play again sometime!" << endl << endl;
				return 0;
			}
		}
		printWord(chosenWord, correctLetters);
	}
	if (iterable == 5)
	{
		cout << "Oh no... You've lost all of your lives! You lose.\nThe correct word was: " << chosenWord << "\nPlay again sometime!" << endl << endl;
	}
	return 0;
}

void arrayStartup(ifstream& in, alphabet& letters, list& wordList) 
{
	string word;
	char letter;
	
	in.open("alphabet.txt");
	for (int i = 0; i < 26; i++)
	{
		in >> letter;
		in.ignore(1);
		letters[i] = letter;		
	}

	in.close();

	in.open("wordlist.txt");
	for (int i = 0; i < 213; i++)
	{
		getline(in, word);
		wordList[i] = word;
	}
	in.close();
}

int letterOrWordCheck()
{
	int x;
	x = 5;
	
	cout << "Are you going to guess a letter or a word?" << endl;
	cout << "If you guess a word it will use all of your guesses." << endl;
	cout << "Please enter 0 for letter or 1 for word." << endl;
	cout << "Ctrl+C to exit" << endl;
	cout << "Input: ";
	cin >> x;
	if (x == 0)
	{
		cout << "You chose to guess a letter." << endl;
		return x;
	}
	else if (x == 1)
	{
		cout << "You chose to guess a word." << endl;
		return x;
	}
	else 
	{
		while (x != (0 || 1))
		{
			cout << string(17, '*') << " Input Error " << string(17, '*') << endl;
			cout << "==> Invalid option entered" << endl;
			cout << "==> Options are 0 for letter or 1 for word" << endl;
			cout << "==> Please try again..." << endl;
			cout << string(47, '*') << endl << endl;
			cout << "Please enter 0 for letter or 1 for word: ";	
			cin >> x;
			if (x == 0)
			{
				cout << "You chose to guess a letter." << endl;
				return x;
			}
			else if (x == 1)
			{
				cout << "You chose to guess a word.";
				return x;
			}
		}
	}  
}

char letGuess()
{
	char letter;
	cout << "Please input a letter: ";
	cin >> letter;
	cout << "Your guess is: " << letter << endl << endl;
	return letter;
}

string wordGuessed()
{
	string word;
	cout << "Please input a word: ";
	cin >> word;
	cout << "Your guess is: " << word << endl << endl;
	return word;
}

int checkLetters(char& letter, string& word, charList& letters)
{
	string iLet;
	
	for (int i = 0; i < (word.length() - 1); i++)
	{
		iLet = word.substr(i,i);
		if(iLet==letter)
		{
			letters[i] = letter;
			return 1;
		}
	}
	return 0;
}

int checkWord(string& guessWord, string& correctWord)
{
	if (guessWord == correctWord)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void printWord(string& chosenWord, charList& lettersList)
{
	int len;
	
	len = (sizeof(lettersList)/sizeof(lettersList[0]));
	
	for (int i = 1; i < len; i++)
	{
		for (int j = 1; j < chosenWord.length(); j++)
		{
			if (chosenWord[j] = lettersList[i])
			{
				cout << lettersList[i];
			}
			else
			{
				cout << "*";
			}
		}
	}
	cout << endl;
	for (int i = 1; i < chosenWord.length(); i++)
	{
		cout << "-";
	}	
	cout << endl << endl;
}