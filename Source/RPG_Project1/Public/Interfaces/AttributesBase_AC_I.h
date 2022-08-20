// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AttributesBase_AC_I.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UAttributesBase_AC_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IAttributesBase_AC_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TryGetHitByEnemy(const float& IncomingPhysicalDamage, const float& IncomingMagicalDamage);
};
