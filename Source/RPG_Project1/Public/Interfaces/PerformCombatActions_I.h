// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PerformCombatActions_I.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPerformCombatActions_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IPerformCombatActions_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PerformAttackRMB();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PerformAttackLMB();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PerformBlock();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void PerformDodge();
};
