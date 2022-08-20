// All rights reserved

#pragma once
#include "TeacherAttributes_F.generated.h"

USTRUCT(BlueprintType)
struct FTeacherAttributes_F
{
	GENERATED_BODY()

	//BasicStats attributes:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	uint8 Physique;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	uint8 Will;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	uint8 Endurance;

	
	//BasicStats regen attributes:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	uint8 WoundClotting;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	uint8 MindPeace;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Attributes")
	uint8 Resting;

	
	//Regulates Damage:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 OneHanded;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 TwoHanded;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Spears;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Gauntlets;

	
	// Regulates Resistances:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 LightArmour;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 MediumArmour;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 HeavyArmour;

	
	// Guild/ Job related:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Alchemy;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Blacksmithing;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Enchanting;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Hunting;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Thievery;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Cooking;

	// Gathering resources related:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 UndergrowthCollecting;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 PreyCollecting;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Mining;

	//Other:
	/** Allows to read more demanding books. More demanding books give more benefits */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Literate;

	/** Allows to speak and make deals with foreigners. The best merchants, teachers and craftsmen are foreigners */ 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Linguists;

	/** Regulates items carry capacity
	 *	Now and then it upgrades random item in player's inventory making it more valuable
	 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Logistics;
};
