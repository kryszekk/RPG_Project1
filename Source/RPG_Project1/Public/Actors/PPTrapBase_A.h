// All rights reserved

//Base class for Pressure plate activated traps.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PPTrapBase_A.generated.h"

UCLASS()
class RPG_PROJECT1_API APPTrapBase_A : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APPTrapBase_A();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
	virtual void TriggerTrap();

	/** Calls function used to apply damage to game pawns derived from BP_CharacterBase */
	UFUNCTION()
	void TryDamageActor(AActor* Actor, float PhysicalDamage, float MagicalDamage);

	////////////////////////////////////////

	/** Amount of PhysicalDamage the trap will inflict upon hit*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	float TrapPhysicalDMG = 100.f;

	/** Amount of MagicalDamage the trap will inflict upon hit*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Damage")
	float TrapMagicalDMG = 100.f;	
};
