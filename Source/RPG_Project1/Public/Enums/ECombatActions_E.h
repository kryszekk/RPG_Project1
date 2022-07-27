// All rights reserved

#pragma once
#include "ECombatActions_E.generated.h"

UENUM(BlueprintType, Category="CombatActions")
enum class ECombatActions_E : uint8
{
	NoAction UMETA(DisplayName = "No combat action"),
	AttackRMB UMETA(DisplayName = "Attack RMB"),
	AttackLMB UMETA(DisplayName = "Attack LMB"),
	Block UMETA(DisplayName = "Block"),
	Dodge UMETA(DisplayName = "Dodge"),
};
