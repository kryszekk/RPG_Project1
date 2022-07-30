// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "ActorComponents/Interactable_AC.h"
#include "GameFramework/Actor.h"
#include "Interfaces/FastTravelSpot_A_I.h"
#include "FastTravelSpot_A.generated.h"

UCLASS()
class RPG_PROJECT1_API AFastTravelSpot_A : public AActor, public IFastTravelSpot_A_I
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFastTravelSpot_A();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bIsDiscovered = false;
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName SpotName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(BlueprintReadWrite)
	UInteractable_AC* InteractComponent;

	////////////////////////////////////////////////////

	virtual void GetIsDiscovered_Implementation(bool& state) override;

	virtual void SetIsDiscovered_Implementation(bool state) override;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
