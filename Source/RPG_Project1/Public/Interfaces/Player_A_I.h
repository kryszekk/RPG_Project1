// All rights reserved

#pragma once

#include "CoreMinimal.h"
//#include "ActorComponents/PlayerAttributes_AC.h"
#include "UObject/Interface.h"
#include "Player_A_I.generated.h"

class UPlayerAttributes_AC;

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UPlayer_A_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IPlayer_A_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void GetPlayerAttributesComponent (UPlayerAttributes_AC*& Component);
};
