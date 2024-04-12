// All rights reserved

#pragma once
#include "PlayerAttributes_F.generated.h"

USTRUCT(BlueprintType)
struct FPlayerAttributes_F
{
	GENERATED_BODY()

	////////////////////// Misc Attributes ///////////////////////////////////
	
	UPROPERTY(BlueprintReadWrite,EditAnywhere)
	uint8 Level = 1;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	float Experience = 0;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	uint8 RestLevel = 255;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	bool bIsDead = false;

	/** These can be spent during talking with teacher to increase an attribute proficiency*/
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int32 LearningPoints = 0;

	/** -Regulates the fine player will have to pay for breaking the law
	*	-If (Bounty > 0) player is wanted
	**/
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	int32 Bounty = 0;
	
	////////////////////////// Basic Stats /////////////////////////////////////
	
	//HP:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float MaxHp;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float CurrentHP;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float HpRegen;

	
	//Mp:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float MaxMp;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float CurrentMp;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float MpRegen;

	
	//Sp:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float MaxSp;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float CurrentSp;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float SpRegen;

	////////////////////////// Combat Stats //////////////////////////

	//defence:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float Armour;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float MagicResistance;

	
	//offence:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float RMB_PhysicalDamage;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float RMB_MagicalDamage;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float LMB_PhysicalDamage;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float LMB_MagicalDamage;
	
	////////////////////// Attributes ////////////////////////////////

	//BasicStats attributes:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Physique = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Will = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Endurance = 10;

	
	//BasicStats regen attributes:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 WoundClotting = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 MindPeace = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Resting = 10;

	
	//Regulates Damage:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 OneHanded = 10;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 TwoHanded = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Spears = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Gauntlets = 10;

	
	// Regulates Resistances:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 LightArmour = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 MediumArmour = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 HeavyArmour = 10;

	
	// Guild/ Job related:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Alchemy = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Blacksmithing = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Enchanting = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Hunting = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Thievery = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Cooking = 10;

	// Gathering resources related:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 UndergrowthCollecting = 10;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 PreyCollecting = 10;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Mining = 10;

	/////////////////////////////////Other////////////////////////////////////////
	
	/** Allows to read more demanding books. More demanding books give more benefits */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Literate = 10;

	/** Allows to speak and make deals with foreigners. The best merchants, teachers and craftsmen are foreigners */ 
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Linguists= 10;

	/** Regulates items carry capacity
	 *	Now and then it upgrades random item in player's inventory making it more valuable
	 */
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	uint8 Logistics = 10;

	/** Regulates How much can player's inventory weigh. After MAx weight is reached player's movement will get restricted*/
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="Attributes")
	float MaxCarryWeight = 50.0f;	
};
