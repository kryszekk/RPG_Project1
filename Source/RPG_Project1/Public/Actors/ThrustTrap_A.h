// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/PPTrapBase_A.h"
#include "ThrustTrap_A.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT1_API AThrustTrap_A : public APPTrapBase_A
{
	GENERATED_BODY()

public:
	AThrustTrap_A();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
	/**Function called by pressure plate to trigger the trap */
	virtual void TriggerTrap() override;
	
	//////////////////////////////////////////////
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	/** Controls how far the thrusting mesh will go */ 
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ThrustDistance = 250.f;

	/** Speed of trap's thrust */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InterpSpeed = 900.f;

	/** Damage that trap will inflict upon hit actor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float PhysicalDamage = 50.f;

	/** Damage that trap will inflict upon hit actor */
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MagicalDamage = 50.f;
	
private:
	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Decides whether Trap is in thrust motion or reverse motion */
	UFUNCTION()
	void DirectionControl(float DeltaTime);

	/** Does thrust motion */
	UFUNCTION()
	void Thrust(float DeltaTime);

	/** Does reverse motion */
	UFUNCTION()
	void Reverse(float DeltaTime);

	////////////////////////////////////////

	/** When true: trap can be triggered. When false: trap is in Reverse and will set this true once it reaches InitialLocation */
	UPROPERTY()
	bool bIsReadyToUse = true;

	/** When false: Actor That triggers OnComponentHit shouldn't be damaged, as the trap is in Reverse motion */
	UPROPERTY()
	bool bIsThrusting = false;
	
	UPROPERTY()
	FVector ThrustTargetLocation;

	UPROPERTY()
	FVector InitialLocation;

	UPROPERTY()
	FVector CurrentLocation;

	/** List of actors that has already been hit during one Thrust motion. It's Used so no actor gets hit more than one time */
	UPROPERTY()
	TArray<AActor*> HitActors; 
	
};
