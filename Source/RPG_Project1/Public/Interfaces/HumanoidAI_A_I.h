// All rights reserved

#pragma once

#include"Enums/WealthClass_E.h"

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HumanoidAI_A_I.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UHumanoidAI_A_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IHumanoidAI_A_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	/** Gets stats required for pickpocket interaction. Wealth class, Current wealth state, unit's level. */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GetWealth(EWealthClass_E& WClass, uint8& WState, uint8& TargetLevel);

	/** Called whenever target unit has just fell victim of pickpocket. This will set victim's wealth state to 0, and start wealth state regeneration */
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void HasBeenPickpocketed();
};
