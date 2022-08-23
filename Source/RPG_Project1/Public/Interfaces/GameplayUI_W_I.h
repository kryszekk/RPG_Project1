// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "GameplayUI_W_I.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UGameplayUI_W_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IGameplayUI_W_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetStatsBarPercentage(const float HpPercentage, const float MpPercentage, const float SpPercentage);
};