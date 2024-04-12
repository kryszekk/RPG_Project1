// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Enums/ChatColour_E.h"

class UWidgetComponent;

#include "Chat_W_I.generated.h"


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UChat_W_I : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_PROJECT1_API IChat_W_I
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SetChatText(const FText& Text, EChatColour_E Colour, UWidgetComponent* Widget, float Duration);

};
