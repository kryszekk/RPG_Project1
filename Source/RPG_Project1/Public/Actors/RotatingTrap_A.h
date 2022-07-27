// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/PPTrapBase_A.h"
#include "RotatingTrap_A.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT1_API ARotatingTrap_A : public APPTrapBase_A
{
	GENERATED_BODY()

public:
	ARotatingTrap_A();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	virtual void TriggerTrap() override;

	UFUNCTION()
	void OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	////////////////////////////
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	/** Controls how much trap's Mesh will rotate.  
	 * Will not rotate more than 179 degrees and less than 1 degree */
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category="Rotation")
	float RotationDegree = 90.f;

	/** Speed of trap's rotation */
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Rotation")
	float InterpSpeed = 300.f;
	
private:
	/** Decides whether Trap is in swing motion or reverse motion */
	UFUNCTION()
	void DirectionControl(float DeltaSeconds);

	/** Does reverse motion */
	UFUNCTION()
	void Reverse(float DeltaSeconds);

	/** Does swing motion */
	UFUNCTION()
	void Swing(float DeltaSeconds);
	
	//////////////////////////////////////

	/** When true: trap can be triggered. When false: trap is in Reverse and will set this true once it reaches InitialLocation */
	UPROPERTY()
	bool bIsReadyToUse = true;

	/** When false: Actor That triggers OnComponentHit shouldn't be damaged, as the trap is in Reverse motion*/
	UPROPERTY()
	bool bIsThrusting = false;

	UPROPERTY()
	FRotator InitialRotation;

	UPROPERTY()
	FRotator TargetRotation;	

	UPROPERTY()
	FRotator CurrentRotation;

	UPROPERTY()
	TArray<AActor*> HitActors;
};
