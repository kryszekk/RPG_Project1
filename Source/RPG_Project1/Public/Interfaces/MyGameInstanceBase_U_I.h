// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Enums/GameDifficulty_E.h"
#include "UObject/Interface.h"
#include "MyGameInstanceBase_U_I.generated.h"

//forward declares
//class EGameDifficulty_E;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMyGameInstanceBase_U_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IMyGameInstanceBase_U_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetGameDifficulty(EGameDifficulty_E& Difficulty);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetGameDifficultyMultiplier(float& Multiplier);

};
