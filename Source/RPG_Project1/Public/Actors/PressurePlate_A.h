// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PressurePlate_A.generated.h"

class UBoxComponent;
class APPTrapBase_A;

UCLASS()
class RPG_PROJECT1_API APressurePlate_A : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APressurePlate_A();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnComponentOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/** Lowers the Mesh */
	UFUNCTION()
	void PlateDescend(float DeltaTime);

	/** Raises the Mesh */
	UFUNCTION()
	void PlateAscend(float DeltaTime);

	/** Decides whether Trap is in thrust motion or reverse motion */
	UFUNCTION()
	void DirectionControl(float DeltaTime);

	///////////////////////////////////////////////
	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UBoxComponent* BoxComponent;

	/** List of traps that will get triggered when this pressure plate gets stepped on */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<APPTrapBase_A*> ControlledTraps;

	/** Regulates how much the plate will recede when stepped on */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float RecedeDistanceZ = 15.f;

	/** Speed of lowering the plate  */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DescendInterpSpeed = 200.f;

private:
	UPROPERTY()
	bool bShouldDescend = true;

	UPROPERTY()
	FVector AscendedTargetL;

	UPROPERTY()
	FVector DescendedTargetL;

	UPROPERTY()
	FVector CurrentL;
};
