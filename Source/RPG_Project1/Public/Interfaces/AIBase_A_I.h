// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AIBase_A_I.generated.h"

class USimpleAttributes_AC;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAIBase_A_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IAIBase_A_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GetSimpleAttributeComponent(USimpleAttributes_AC*& SA_Component);
};
