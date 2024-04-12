// All rights reserved

#pragma once
#include "ChatColour_E.generated.h"

UENUM(BlueprintType)
enum class EChatColour_E : uint8
{
	Normal UMETA(DisplayName = "Normal"),
	Quest UMETA(DisplayName = "Quest"),
	Warning UMETA(DisplayName = "Warning"),
};
