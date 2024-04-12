// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "Actors/PPTrapBase_A.h"
#include "FallTrap_A.generated.h"

/**
 * 
 */
UCLASS()
class RPG_PROJECT1_API AFallTrap_A : public APPTrapBase_A
{
	GENERATED_BODY()

public:
	AFallTrap_A();
	virtual void Tick(float DeltaSeconds) override;
	virtual void TriggerTrap() override;
	virtual void BeginPlay() override;

	/////////////////////////////////////////////
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* Mesh;

	/** Controls how much trap's Mesh will rotate.  
	 * Will not rotate more than 90 degrees and less than 1 degree */
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float RotationDegree = 90.f;

	/** Speed of trap's rotation */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float InterpSpeed = 100.f;

private:
	UFUNCTION()
	void DirectionControl(float DeltaSeconds);

	UFUNCTION()
	void ThrustRotation(float DeltaSeconds);

	UFUNCTION()
	void ReverseRotation(float DeltaSeconds);
	
	//////////////////////////////////////////////

	/** When true: trap can be triggered. When false: trap is in Reverse and will set this true once it reaches InitialLocation */
	UPROPERTY()
	bool bIsReadyToUse = true;

	UPROPERTY()
	FRotator CurrentRotation;

	UPROPERTY()
	FRotator TargetRotation;

	UPROPERTY()
	FRotator InitialRotation;
};
