// All rights reserved

#pragma once
#include "WeaponType_E.generated.h"

UENUM(BlueprintType)
enum class EWeaponType_E : uint8
{
	OneHanded	UMETA(DisplayName = "One handed"),

	TwoHanded	UMETA(DisplayName = "Two handed"),

	Spears	UMETA(DisplayName = "Spears"),

	Gauntlets	UMETA(DisplayName = "Gauntlets"),
};
