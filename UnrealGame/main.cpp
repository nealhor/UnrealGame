
#pragma once
#include <iostream>
#include <string>
#include "FGame.h"
using namespace std;
using int32 = int;

void PrintIntro();
void PlayGame();
void PrintGameSummary();
string GetValidGuess();
bool AskToPlayAgain();

FGame BCGame; // instantiate a new game 

// start of the game
int main()
{
	
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
		
	} while (bPlayAgain);
	return 0;
}
void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)  {
		string Guess = GetValidGuess();
		
			FBullCowCount BullCowCounter = BCGame.SubmitValidGuess(Guess);
		cout << "Bulls = " << BullCowCounter.Bulls << " ";
		cout << "Cow = " << BullCowCounter.Cow << " ";
		
	}
	PrintGameSummary();
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		cout << "YOU WON!!!";
	}
	else
	{
		cout << "YOU LOSE!!!";
	}






}
void PrintIntro()
{
	// introduce the game
	
	cout << "Guess the word\n";
	cout << "The word have " << BCGame.GetHiddenWordLength();
	cout << " letters \n";
	
	return;
}

string GetValidGuess() {
	string Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
	int32 CurrentTry = BCGame.GetCurrentTry();

	cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries(); 
	cout << " Enter your guess ";
	
	getline(cin, Guess);
	

	Status = BCGame.CheckGuessValidity(Guess);
	switch (Status)
	{

	case EGuessStatus::Not_Isogram:
		cout << "enter a word without repeating letters. /n";
		break;
	case EGuessStatus::Wrong_Legth:
		cout << "Enter a " << BCGame.GetHiddenWordLength() << " Letter Word \n\n";
		break;
	case EGuessStatus::Not_Lowercase:
		cout << "enter all lowercase latter \n\n";
		break;
	default:
		break;
		
		
	}
	
	} while (Status != EGuessStatus::OK); // keep looping until no errors
	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want too play again with the same word?(y / n)";
	string Response = "";
	getline(cin, Response);
	system("pause");
	return (Response[0] == 'y') || (Response[0] == 'Y');

}



