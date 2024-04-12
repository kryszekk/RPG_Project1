// All rights reserved


#include "MyGameInstanceBase_U.h"

//constructor
UMyGameInstanceBase_U::UMyGameInstanceBase_U()
{
}

void UMyGameInstanceBase_U::GetGameDifficulty_Implementation(EGameDifficulty_E& Difficulty)
{
	IMyGameInstanceBase_U_I::GetGameDifficulty_Implementation(Difficulty);
	Difficulty = EGameDifficulty;
	return;
}

void UMyGameInstanceBase_U::GetGameDifficultyMultiplier_Implementation(float& Multiplier)
{
	IMyGameInstanceBase_U_I::GetGameDifficultyMultiplier_Implementation(Multiplier);
	Multiplier = GameDifficultyMultiplier;
}

void UMyGameInstanceBase_U::SetGameDifficulty(EGameDifficulty_E Difficulty)
{
	switch (Difficulty)
	{
	case EGameDifficulty_E::VeryEasy:
		GameDifficultyMultiplier = 0.4f;
		break;
	case EGameDifficulty_E::Easy:
		GameDifficultyMultiplier = 0.8f;
		break;
	case EGameDifficulty_E::Normal:
		GameDifficultyMultiplier = 1.0f;
		break;
	case EGameDifficulty_E::Hard:
		GameDifficultyMultiplier = 1.75f;
		break;
	case EGameDifficulty_E::Hardcore:
		GameDifficultyMultiplier = 2.5f;
		break;
	}
	return;
}
