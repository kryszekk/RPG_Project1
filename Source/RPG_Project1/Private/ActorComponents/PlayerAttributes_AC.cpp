// All rights reserved


#include "ActorComponents/PlayerAttributes_AC.h"
#include "Enums/ApparelKind_E.h"
#include "Enums/CombatActions_E.h"
#include "Interfaces/CharacterBase_A_I.h"

UPlayerAttributes_AC::UPlayerAttributes_AC()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UPlayerAttributes_AC::BeginPlay()
{
	Super::BeginPlay();
	SetInitialStats();
}

void UPlayerAttributes_AC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UPlayerAttributes_AC::TryGetHitByEnemy_Implementation(const float& IncomingPhysicalDamage,
	const float& IncomingMagicalDamage)
{
	Super::TryGetHitByEnemy_Implementation(IncomingPhysicalDamage, IncomingMagicalDamage);

	ECombatActions_E DefenderCurrentAction;
	if(GetOwner()->GetClass()->ImplementsInterface(UCharacterBase_A_I::StaticClass()))
	{
		ICharacterBase_A_I::Execute_GetCurrentCombatAction(GetOwner(),DefenderCurrentAction);
	}
	else
	{
		UE_LOG(LogTemp,Error,TEXT("Actor that was hit doesn't implement UCharacterBase_A_I interface"));
	}
	
	switch (DefenderCurrentAction)
	{
	case ECombatActions_E::NoAction:
		InflictDamage(IncomingPhysicalDamage, IncomingMagicalDamage);
		break;
		
	case ECombatActions_E::AttackRMB:
		InflictDamage(IncomingPhysicalDamage, IncomingMagicalDamage);
		break;
		
	case ECombatActions_E::AttackLMB:
		InflictDamage(IncomingPhysicalDamage, IncomingMagicalDamage);
		break;
		
	case ECombatActions_E::Block:
		ICharacterBase_A_I::Execute_BlockedBlow(GetOwner());
		break;
		
	case ECombatActions_E::Dodge:
		ICharacterBase_A_I::Execute_DodgedBlow(GetOwner());
		break;
	}
}

////////////////////////////////////////////////////////////////

float UPlayerAttributes_AC::CalculateRestMultiplier()
{
	//Most of the time return float will be at 1.1
	//But after long time without a sleep it will fall to as low as 0.5

	float temp = std::min(110.f, static_cast<float>(PAttributes.RestLevel)) /100;
	return std::max(temp, 0.5f);
}


void UPlayerAttributes_AC::SetMaxHpMpSp(float RestMultiplier)
{
	//5 points are granted per each level
	float BaseStats = 7.0f * static_cast<float>(PAttributes.Level);
	
	//set MaxHp
	PAttributes.MaxHp = RestMultiplier * BaseStats * (PAttributes.Physique/2);
	//set MaxMp
	PAttributes.MaxMp = RestMultiplier * BaseStats * (PAttributes.Will/2);
	//set MaxSp
	PAttributes.MaxSp = RestMultiplier * BaseStats * (PAttributes.Endurance/2);
	
}

void UPlayerAttributes_AC::SetCurrentHpMpSp(float Hp, float Mp, float Sp)
{
	PAttributes.CurrentHP = Hp;
	PAttributes.CurrentMp = Mp;
	PAttributes.CurrentSp = Sp;
}

void UPlayerAttributes_AC::SetRegen(const float& RestMultiplier)
{
	//Hp
	PAttributes.HpRegen = (PAttributes.WoundClotting /2) * (PAttributes.Level * 0.4f) * RestMultiplier;
	//Mp
	PAttributes.MpRegen = (PAttributes.MindPeace / 2) * (PAttributes.Level * 1.1f) * RestMultiplier;
	//Sp
	PAttributes.SpRegen = (PAttributes.Endurance / 2) * (PAttributes.Level * 1.1f) * RestMultiplier;
}

void UPlayerAttributes_AC::SetInitialStats()
{
	const float RestMultiplier = CalculateRestMultiplier();
	SetMaxHpMpSp(RestMultiplier);
	SetCurrentHpMpSp(PAttributes.MaxHp, PAttributes.MaxMp, PAttributes.MaxSp);
	SetRegen(RestMultiplier);
	SetMaxCarryWeight(RestMultiplier);
}

void UPlayerAttributes_AC::RecalculatePAttributesStats()
{
	const float RestMultiplier = CalculateRestMultiplier();
	SetMaxHpMpSp(RestMultiplier);
	SetRegen(RestMultiplier);
	SetMaxCarryWeight(RestMultiplier);
}


void UPlayerAttributes_AC::SetDamage_RMB(const float& RestMultiplier, const EWeaponType_E& EWeaponType_E, const float& RMB_PhysicalDamage, const float& RMB_MagicalDamage)
{
	switch (EWeaponType_E)
	{
	case EWeaponType_E::OneHanded:
		PAttributes.RMB_PhysicalDamage =(RMB_PhysicalDamage) * (PAttributes.OneHanded/10) * RestMultiplier;
		PAttributes.RMB_MagicalDamage =(RMB_MagicalDamage) * (PAttributes.OneHanded/10) * RestMultiplier;
		break;
	case EWeaponType_E::TwoHanded:
		PAttributes.RMB_PhysicalDamage =(RMB_PhysicalDamage) * (PAttributes.TwoHanded/10) * RestMultiplier;
		PAttributes.RMB_MagicalDamage =(RMB_MagicalDamage) * (PAttributes.TwoHanded/10) * RestMultiplier;
		break;
	case EWeaponType_E::Spears:
		PAttributes.RMB_PhysicalDamage =(RMB_PhysicalDamage) * (PAttributes.Spears/10) * RestMultiplier;
		PAttributes.RMB_MagicalDamage =(RMB_MagicalDamage) * (PAttributes.Spears/10) * RestMultiplier;
		break;
	case EWeaponType_E::Gauntlets:
		PAttributes.RMB_PhysicalDamage =(RMB_PhysicalDamage) * (PAttributes.Gauntlets/10) * RestMultiplier;
		PAttributes.RMB_MagicalDamage =(RMB_MagicalDamage) * (PAttributes.Gauntlets/10) * RestMultiplier;
		break;
	}
	return;
}

void UPlayerAttributes_AC::SetDamage_LMB(const float& RestMultiplier, const EWeaponType_E& EWeaponType_E, const float& LMB_PhysicalDamage, const float& LMB_MagicalDamage)
{
	switch (EWeaponType_E)
	{
	case EWeaponType_E::OneHanded:
		PAttributes.LMB_PhysicalDamage =(LMB_PhysicalDamage) * (PAttributes.OneHanded/10) * RestMultiplier;
		PAttributes.LMB_MagicalDamage =(LMB_MagicalDamage) * (PAttributes.OneHanded/10) * RestMultiplier;
		break;
	case EWeaponType_E::TwoHanded:
		PAttributes.LMB_PhysicalDamage =(LMB_PhysicalDamage) * (PAttributes.TwoHanded/10) * RestMultiplier;
		PAttributes.LMB_MagicalDamage=(LMB_MagicalDamage) * (PAttributes.TwoHanded/10) * RestMultiplier;
		break;
	case EWeaponType_E::Spears:
		PAttributes.LMB_PhysicalDamage =(LMB_PhysicalDamage) * (PAttributes.Spears/10) * RestMultiplier;
		PAttributes.LMB_MagicalDamage=(LMB_MagicalDamage) * (PAttributes.Spears/10) * RestMultiplier;
		break;
	case EWeaponType_E::Gauntlets:
		PAttributes.LMB_PhysicalDamage=(LMB_PhysicalDamage) * (PAttributes.Gauntlets/10) * RestMultiplier;
		PAttributes.LMB_MagicalDamage=(LMB_MagicalDamage) * (PAttributes.Gauntlets/10) * RestMultiplier;
		break;
	}
	return;	
}

void UPlayerAttributes_AC::SetWholeArmour(const float& RestMultiplier, const float& TorsoArmour, const float& TorsoMRes, const EApparelKind_E& TorsoKind, const float& GlovesArmour, const float& GlovesMRes, const EApparelKind_E& GlovesKind, const float& PantsArmour, const float& PantsMRes, const EApparelKind_E& PantsKind, const float& BootsArmour, const float& BootsMRes, const EApparelKind_E& BootsKind)
{
	PAttributes.Armour = 0.0f;
	PAttributes.MagicResistance = 0.0f;

	//Sets Torso Armour and MRes
	switch (TorsoKind)
	{
	case EApparelKind_E::LightArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.LightArmour/10) * TorsoArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.LightArmour/10) * TorsoMRes;
		break;
	case EApparelKind_E::MediumArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.MediumArmour/10) * TorsoArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.MediumArmour/10) * TorsoMRes;
		break;
	case EApparelKind_E::HeavyArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.HeavyArmour/10) * TorsoArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.HeavyArmour/10) * TorsoMRes;
	}

	//Sets Gloves Armour and MRes
	switch (GlovesKind)
	{
	case EApparelKind_E::LightArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.LightArmour/10) * GlovesArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.LightArmour/10) * GlovesMRes;
		break;
	case EApparelKind_E::MediumArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.MediumArmour/10) * GlovesArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.MediumArmour/10) * GlovesMRes;
		break;
	case EApparelKind_E::HeavyArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.HeavyArmour/10) * TorsoArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.HeavyArmour/10) * GlovesMRes;
	}
	
	//Sets Pants Armour and MRes
	switch (GlovesKind)
	{
	case EApparelKind_E::LightArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.LightArmour/10) * PantsArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.LightArmour/10) * PantsMRes;
		break;
	case EApparelKind_E::MediumArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.MediumArmour/10) * PantsArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.MediumArmour/10) * PantsMRes;
		break;
	case EApparelKind_E::HeavyArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.HeavyArmour/10) * PantsArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.HeavyArmour/10) * PantsMRes;
	}
	
	//Sets Boots Armour and MRes
	switch (GlovesKind)
	{
	case EApparelKind_E::LightArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.LightArmour/10) * BootsArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.LightArmour/10) * BootsMRes;
		break;
	case EApparelKind_E::MediumArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.MediumArmour/10) * BootsArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.MediumArmour/10) * BootsMRes;
		break;
	case EApparelKind_E::HeavyArmour:
		PAttributes.Armour += RestMultiplier * (PAttributes.HeavyArmour/10) * BootsArmour;
		PAttributes.MagicResistance += RestMultiplier * (PAttributes.HeavyArmour/10) * BootsMRes;
	}
	return;
}

void UPlayerAttributes_AC::SetMaxCarryWeight(const float& RestMultiplier)
{
	//2.5kg of carry weight per each point in logistics Attribute
	//Base carry weight is 50 kg
	// So: MaxCarryWeight = BaseCarryWeight + LogisticsCarryWeight * RestMultiplier
	PAttributes.MaxCarryWeight = 50.0f + (static_cast<float>(PAttributes.Logistics) * 2.5f) * RestMultiplier;
}


void UPlayerAttributes_AC::InflictDamage(const float& IncPhysicalDamage, const float& IncMagicalDamage)
{
	float Damage;
	Damage = CalculateReceivedDamage(IncPhysicalDamage, IncMagicalDamage, PAttributes.Armour, PAttributes.MagicResistance);
	PAttributes.CurrentHP = PAttributes.CurrentHP - Damage;
	ShouldUnitDie(PAttributes.CurrentHP, PAttributes.bIsDead);

	UE_LOG(LogTemp,Error,TEXT("Unit's current hp %f"), PAttributes.CurrentHP);
	
	if (PAttributes.bIsDead)
	{
		//call inflicted damage and dies
		ICharacterBase_A_I::Execute_InflictedDamageAndDies(GetOwner());
		//TODO do here gain exp by player that inflicted this final blow
	}
	else
	{
		// call inflicted damage but lives
		ICharacterBase_A_I::Execute_InflictedDamageButLives(GetOwner());
	}
	return;
}

