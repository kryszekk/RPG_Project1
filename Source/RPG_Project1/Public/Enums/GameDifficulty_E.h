// All rights reserved

#pragma once
#include "GameDifficulty_E.generated.h"

UENUM(BlueprintType)
enum class EGameDifficulty_E :uint8
{
	/** multiplier value 0.4 */
	VeryEasy UMETA(DisplayName = "Very easy"),

	/** multiplier value 0.8 */
	Easy UMETA(DisplayName = "Easy"),

	/** multiplier value 1 */
	Normal UMETA(DisplayName = "Normal"),

	/** multiplier value 1.75 */
	Hard UMETA(DisplayName = "Hard"),

	/** multiplier value 2.5 */
	Hardcore UMETA(DisplayName = "Hardcore"),
};

