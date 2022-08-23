// All rights reserved

#pragma once
#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EWealthClass_E : uint8
{
	Poor		UMETA(DisplayName = "Poor"),

	Peasants	UMETA(DisplayName = "Peasants"),

	Townsmen	UMETA(DisplayName = "Townsmen"),

	Mercenary	UMETA(DisplayName = "Mercenary"),
	
	Craftsmen	UMETA(DisplayName = "Craftsmen"),

	Merchants	UMETA(DisplayName = "Merchants"),

	Knights		UMETA(DisplayName = "Knights"),

	Royalty		UMETA(DisplayName = "Royalty"),
	
};
