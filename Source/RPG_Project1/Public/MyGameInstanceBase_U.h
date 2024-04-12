// All rights reserved

#pragma once

#include "Enums/GameDifficulty_E.h"
#include "Interfaces/MyGameInstanceBase_U_I.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstanceBase_U.generated.h"


UCLASS()
class RPG_PROJECT1_API UMyGameInstanceBase_U : public UGameInstance, public IMyGameInstanceBase_U_I
{
	GENERATED_BODY()

public:
	UMyGameInstanceBase_U();
	
	
public:
	
	UFUNCTION()
	virtual void GetGameDifficulty_Implementation(EGameDifficulty_E& Difficulty) override;

	UFUNCTION()
	virtual void GetGameDifficultyMultiplier_Implementation(float& Multiplier) override;

	UFUNCTION()
	void SetGameDifficulty(EGameDifficulty_E Difficulty);
	///////////////////
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EGameDifficulty_E EGameDifficulty = EGameDifficulty_E::Normal;

	UPROPERTY()
	float GameDifficultyMultiplier = 1.0f;
};
