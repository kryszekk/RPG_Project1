// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FastTravelSpot_A_I.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UFastTravelSpot_A_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IFastTravelSpot_A_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetIsDiscovered (bool& state);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void SetIsDiscovered(bool state);
};


//&Out GetIsDiscovered
//In SetIsDiscovered