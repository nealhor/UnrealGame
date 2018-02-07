#pragma once
#include <string>
using int32 = int;
using FString = std::string;


struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cow = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Legth,
	Not_Lowercase
};

class FGame {
public:
	FGame(); // constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString);

	void Reset(); // TODO
	

	FBullCowCount SubmitValidGuess(FString);


private:
	// look constructor
	int32 MyCurrentTry;
	
	FString MyHiddenWord;
	bool bGameIsWon;


	bool IsIsogram(FString) const;
	bool Islowercase(FString) const;
};