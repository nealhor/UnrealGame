#pragma once
#include "FGame.h"
#include <map>
#define Tmap std::map
using int32 = int;
using FString = std::string;





void FGame::Reset()
{
	
	
	constexpr int32 CURRENT_TRY = 1;
	MyCurrentTry = CURRENT_TRY;
	const FString HIDEN_WORD = "planet";
	MyHiddenWord = HIDEN_WORD;
	bGameIsWon = false;
	return;
}

FBullCowCount FGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;


	int32 WordLength = MyHiddenWord.length();
	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < WordLength; j++) {
			if (Guess[j] == MyHiddenWord[i]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cow++;

				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}
int32 FGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}
int32 FGame::GetMaxTries() const
{
	Tmap<int32, int32> WordLengthToMaxTries{ {3,6}, {4,7}, {5,10}, {6,17} };
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

bool FGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }
	
	Tmap<char, bool> LetterSeen;
	for (auto Letter : Word)  // for all letter in the world
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) 
		{ 
		return false; 
		}
		else {
			LetterSeen[Letter] = true;
		}
	
	
	}
	return true;
}

bool FGame::Islowercase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter))
		{
			return false;
		}
	}
	return true;
}


FGame::FGame()
{
	Reset();
}



int32 FGame::GetCurrentTry()const
{
	return MyCurrentTry;
}



bool FGame::IsGameWon()const
{
	return bGameIsWon;
}

EGuessStatus FGame::CheckGuessValidity(FString Guess)
{
	if (!IsIsogram(Guess)) {

		return EGuessStatus::Not_Isogram;

	}
	else if (!Islowercase(Guess)) {

		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength() )
	{
		return EGuessStatus::Wrong_Legth;
	}
	else {
		return EGuessStatus::OK;
	}

}
