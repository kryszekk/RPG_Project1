// All rights reserved


#include "Actors/FastTravelSpotsController_A.h"

#include "EngineUtils.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFastTravelSpotsController_A::AFastTravelSpotsController_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
}

// Called when the game starts or when spawned
void AFastTravelSpotsController_A::BeginPlay()
{
	Super::BeginPlay();

	//It will log the names of all controlled FastTravelSpots
	for(AFastTravelSpot_A* Spot : FTSpots)
	{
		if(Spot)
		{
			UE_LOG(LogTemp, Warning, TEXT("Name of Spot is: %s"), *Spot->SpotName.ToString());
		}
	}
	
}

// Called every frame
void AFastTravelSpotsController_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


