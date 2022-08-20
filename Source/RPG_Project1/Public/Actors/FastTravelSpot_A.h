// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/FastTravelSpot_A_I.h"

#include "FastTravelSpot_A.generated.h"

class UInteractable_AC;

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

	//** Set it to true if you want to set TargetSpot in editor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Target Spot")
	bool bCustomTargetSpot = false;
	
	/** Transform ot the spot where player will be teleported to if he chose to
	 * be teleported to this Fast travel spot	*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Target Spot")
	FTransform TargetSpot;
	
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
