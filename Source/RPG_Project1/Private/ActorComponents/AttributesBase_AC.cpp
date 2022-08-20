// All rights reserved


#include "ActorComponents/AttributesBase_AC.h"

// Sets default values for this component's properties
UAttributesBase_AC::UAttributesBase_AC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAttributesBase_AC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAttributesBase_AC::TryGetHitByEnemy_Implementation(const float& IncomingPhysicalDamage,
	const float& IncomingMagicalDamage)
{
	IAttributesBase_AC_I::TryGetHitByEnemy_Implementation(IncomingPhysicalDamage, IncomingMagicalDamage);
}


// Called every frame
void UAttributesBase_AC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	// ...
}


float UAttributesBase_AC::CalculateReceivedDamage(const float& PhysicalDamage, const float& MagicalDamage, const float& DefenderArmour, const float& DefenderMRes)
{
	// minimal damage is 1% of all incoming damage
	float TotalMinimalDamage = (PhysicalDamage*0.005f) + (MagicalDamage*0.005f);

	// damage post Armour/MResistance reduction
	float RawPhysicalDamage = std::max(0.0f, (PhysicalDamage - DefenderArmour )); 
	float RawMagicalDamage = std::max(0.0f, MagicalDamage - DefenderMRes);

	// total Raw damage
	float TotalRawDamage = RawPhysicalDamage + RawMagicalDamage;

	if (TotalRawDamage>TotalMinimalDamage)
	{
		return TotalRawDamage; 
	}
	else
	{
		return TotalMinimalDamage;
	}
}

void UAttributesBase_AC::ShouldUnitDie(const float& HpAtTheMoment, bool& bIsDead)
{
	if (HpAtTheMoment <= 0)
	{
		bIsDead = true;
		return;
	}
	else
	{
		return;
	}
	return;
}