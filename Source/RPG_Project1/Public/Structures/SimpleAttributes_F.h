// All rights reserved

#pragma once
#include "SimpleAttributes_F.generated.h"

USTRUCT(BlueprintType)
struct FSimpleAttributes_F
{
	GENERATED_BODY()
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="MainStats")
	uint8 Level = 1;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="MainStats")
	bool bIsDead = false;

	////////////////// Balance Multiplier: /////////////////////
	
	/** Main multiplier to regulate overall strength of this unit
	*	It amplifies all stats. */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="MainStats")
	float BalanceMultiplier = 1;

	//////////////////////////// Combat Stats ///////////////////////////
	
	/** Damage type that unit inflicts
	*	false - Physical
	*	true - Magical */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="CombatStats")
	bool bDamageType;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats") 
	float PhysicalDamage;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float MagicalDamage;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float Armour;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="CombatStats")
	float MagicResistance;

	////////////////////////// Basic Stats /////////////////////////////////////

	//HP
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float MaxHp;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float CurrentHP;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float HpRegen;

	//Mp
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float MaxMp;
	
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float CurrentMp;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float MpRegen;

	//Sp
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float MaxSp;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float CurrentSp;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category="BasicStats")
	float SpRegen;
	
	////////////////////// Proficiency perks ////////////////////////////////
	// these variables are used for specifying strengths and weaknesses of a unit
	// when bCustomProficiency is set to true I will be able to specify stats of the unit

	/** if false Proficiency stats wil lbe set automatically based on level */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	bool bCustomProficiency = false;

	/** Regulates Damage*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 WeaponProficiency = 10;

	/** Regulates Magic damage */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 MagicProficiency = 10;

	/** Regulates Armour amount*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 ArmourProficiency = 10;

	/** Regulates Magic resist amount*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 MagicResistanceProficiency = 10;
	
	/** Regulates Hp amount */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Physique = 10;

	/** Regulates Mp amount */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Will = 10;

	/** Regulates Sp amount */
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Attributes")
	uint8 Endurance = 10;
	
};
