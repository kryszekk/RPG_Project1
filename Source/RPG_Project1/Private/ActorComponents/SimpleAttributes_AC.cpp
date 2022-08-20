// All rights reserved

#include "ActorComponents/SimpleAttributes_AC.h"
#include "ActorComponents/CombatActions_AC.h"
#include "interfaces/MyGameInstanceBase_U_I.h"
#include "Interfaces/CharacterBase_A_I.h"
#include "Kismet/GameplayStatics.h"

USimpleAttributes_AC::USimpleAttributes_AC()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void USimpleAttributes_AC::BeginPlay()
{
	Super::BeginPlay();
	ProcedurallySetAttributes();
}

void USimpleAttributes_AC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void USimpleAttributes_AC::TryGetHitByEnemy_Implementation(const float& IncomingPhysicalDamage, const float& IncomingMagicalDamage)
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

//////////////////////////////////////////////////////////////////////////

void USimpleAttributes_AC::ProcedurallySetAttributes()
{
	float GameDifficultyMultiplier;
	//															Alternative way of getting game instance:
	//															this->GetWorld()->GetGameInstance()
	IMyGameInstanceBase_U_I::Execute_GetGameDifficultyMultiplier(UGameplayStatics::GetGameInstance(this), GameDifficultyMultiplier);
	
	if (!SAttributes.bCustomProficiency)
	{
		SAttributes.WeaponProficiency = std::max(10,SAttributes.Level /2) * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
		SAttributes.MagicProficiency = std::max(10 ,SAttributes.Level /2) * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
		SAttributes.ArmourProficiency = std::max(10,SAttributes.Level /2) * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
		SAttributes.MagicProficiency = std::max(10, SAttributes.Level /2) * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
		
		SAttributes.Physique = std::max(10, SAttributes.Level /2) * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
		SAttributes.Will = std::max(10, SAttributes.Level /2) * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
		SAttributes.Endurance = std::max(10, SAttributes.Level /2) * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
	}
	//Set Regen Proficiency
	const float RegenProficiency = std::max(10,SAttributes.Level /2) * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;


	//float BaseStats = 7.0f * static_cast<float>(SAttributes.Level);
	//Hp																SAttributes.Level * (Amount of hits required to kill it when the same actors fight)
	SAttributes.MaxHp = std::max(1,SAttributes.Physique /2) * (SAttributes.Level * 7) * 1.1 * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
	SAttributes.CurrentHP = SAttributes.MaxHp;
	SAttributes.HpRegen = (RegenProficiency /2) * (SAttributes.Level * 0.4f) * 1.1 * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
	
	//Mp
	SAttributes.MaxMp = std::max(1,SAttributes.Will /2) * (SAttributes.Level * 7) * 1.1 * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
	SAttributes.CurrentMp = SAttributes.MaxMp;
	SAttributes.MpRegen = (RegenProficiency / 2) * (SAttributes.Level * 1.1f) * 1.1 * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
	//SAttributes.MpRegen = SAttributes.MaxMp/10;

	//Sp
	SAttributes.MaxSp = std::max(1,SAttributes.Endurance /2) * (SAttributes.Level * 7) * 1.1 * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
	SAttributes.CurrentSp = SAttributes.MaxSp;
	SAttributes.SpRegen = (RegenProficiency /2) * (SAttributes.Level * 1.1f) * 1.1 * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
	//SAttributes.SpRegen = SAttributes.MaxSp/10;
	
	//Damage
	if(SAttributes.bDamageType)
	{
		SAttributes.MagicalDamage =(SAttributes.Level*5) * (SAttributes.MagicProficiency/10) * 1.1f * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
		SAttributes.PhysicalDamage = 0;
	}
	else
	{
		//							Weapons on average get 5dmg per level,	Proficiency multiplier,  * 1.1f Rest multiplier, * unit balance multiplier, * Game difficulty multiplier
		SAttributes.PhysicalDamage =(SAttributes.Level*5) * (SAttributes.WeaponProficiency/10) * 1.1f * SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
		SAttributes.MagicalDamage = 0;
	}

	//Deff
	SAttributes.Armour =(SAttributes.Level*2.5f) * (SAttributes.ArmourProficiency/10) * 1.1f *SAttributes.BalanceMultiplier * GameDifficultyMultiplier;
	SAttributes.MagicResistance =(SAttributes.Level*2.5f) * (SAttributes.MagicResistanceProficiency/10) * 1.1f *SAttributes.BalanceMultiplier * GameDifficultyMultiplier;

	return;
}

void USimpleAttributes_AC::InflictDamage(const float& IncPhysicalDamage, const float& IncMagicalDamage)
{
	//UE_LOG(LogTemp,Display, TEXT("Inc phys dmg %f, inc magic dmg %f"), IncPhysicalDamage, IncMagicalDamage);
	
	float Damage;
	Damage = CalculateReceivedDamage(IncPhysicalDamage, IncMagicalDamage, SAttributes.Armour, SAttributes.MagicResistance);
	SAttributes.CurrentHP = SAttributes.CurrentHP - Damage;
	ShouldUnitDie(SAttributes.CurrentHP, SAttributes.bIsDead);

	UE_LOG(LogTemp,Error,TEXT("Unit's current hp %f"), SAttributes.CurrentHP);
	
	if (SAttributes.bIsDead)
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

