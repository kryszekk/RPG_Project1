// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Bed_A_I.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBed_A_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IBed_A_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void GetCurrentlyUsed(bool& State);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void SetCurrentlyUsed(bool State);
};
