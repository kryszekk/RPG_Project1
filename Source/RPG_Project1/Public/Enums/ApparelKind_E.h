// All rights reserved

#pragma once
#include "ApparelKind_E.generated.h"

UENUM(BlueprintType)
enum class EApparelKind_E :uint8
{
	
	LightArmour UMETA(DisplayName = "Light armour"),
	
	MediumArmour UMETA(DisplayName = "Medium armour"), 
	
	HeavyArmour UMETA(DisplayName = "Heavy armour"),
};
