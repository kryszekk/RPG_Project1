// All rights reserved

#pragma once

#include "Interfaces/AttributesBase_AC_I.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"	//Can I get rid of this include?
#include "AttributesBase_AC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_PROJECT1_API UAttributesBase_AC : public UActorComponent, public IAttributesBase_AC_I
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributesBase_AC();

protected: 
	// Called when the game starts
	virtual void BeginPlay() override;

	/** Checks whether this unit should ReceiveHitDamage() or not because it was dodging or blocking **/
	virtual void TryGetHitByEnemy_Implementation(const float& IncomingPhysicalDamage, const float& IncomingMagicalDamage) override;

	/** Calculates and returns float damage that should be dealt to the defender unit */
	UFUNCTION()
	float CalculateReceivedDamage(const float& PhysicalDamage, const float& MagicalDamage, const float& DefenderArmour, const float& DefenderMRes);

	/** Checks Current hp and decides whether or not unit should be dead*/
	UFUNCTION()
	void ShouldUnitDie(const float& HpAtTheMoment, bool& bIsDead);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
};
