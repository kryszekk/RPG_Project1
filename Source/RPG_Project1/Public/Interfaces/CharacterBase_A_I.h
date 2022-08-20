// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Enums/CombatActions_E.h"
#include "UObject/Interface.h"
#include "CharacterBase_A_I.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UCharacterBase_A_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API ICharacterBase_A_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	/** Calls interface function implemented in BP_Player or BP_AIBase */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Combat, Attributes Functions")
	void InflictedDamageButLives();

	/** Calls interface function implemented in BP_Player or BP_AIBase */
	UFUNCTION( BlueprintCallable, BlueprintImplementableEvent, Category="Combat, Attributes Functions")
	void InflictedDamageAndDies();

	/** Calls interface function implemented in BP_Player or BP_AIBase */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Combat, Attributes Functions")
	void BlockedBlow();

	/** Calls interface function implemented in BP_Player or BP_AIBase */
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, Category="Combat, Attributes Functions")
	void DodgedBlow();

	/** Outputs unit's current combat action Implemented in CharacterBase_A */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void GetCurrentCombatAction(ECombatActions_E& Action);
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="AI, BTT related")
	void GetLocation(FVector& Location);
	
};
