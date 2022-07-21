// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LeverDoor_A.generated.h"

UCLASS()
class RPG_PROJECT1_API ALeverDoor_A : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALeverDoor_A();

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
	float TargetDistanceZ = 240;

	UPROPERTY(EditAnywhere)
	float InterpSpeed = 40;
	
///////////////////////////////////////////////////////

	UFUNCTION(BlueprintCallable)
	void TriggerDoor();
		
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	FVector CurrentL;

	UPROPERTY()
	FVector TargetOpenL;

	UPROPERTY()
	FVector TargetCloseL;

	UPROPERTY()
	bool bShouldOpen = true;

/////////////////////////////////////////////

	UFUNCTION()
	void Open(float DeltaTime);

	UFUNCTION()
	void Close(float DeltaTime);

	UFUNCTION()
	void OpenOrClose(float DeltaTime);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
