// All rights reserved

#pragma once

#include "CoreMinimal.h"
#include "FastTravelSpot_A.h"
#include "GameFramework/Actor.h"
#include "FastTravelSpotsController_A.generated.h"

UCLASS()
class RPG_PROJECT1_API AFastTravelSpotsController_A : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFastTravelSpotsController_A();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AFastTravelSpot_A*> FTSpots;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};


/*Note on how to use This class in conjunction with class FastTravelSign_A
 *
 *1. There must be only one FastTravelSignsController_A instance per level.
 *2. I can have as much FastTravelSign_A in level as I want.
 *3. In editor I need to add any controlled FastTravellSpot to the array in this class
 *
 * Player will be able to Fast travel between FastTravelSign_A instances.
 * But for the first player has to discover/activate given FastTravelSign_A in order to be able to use it.
 *
 */