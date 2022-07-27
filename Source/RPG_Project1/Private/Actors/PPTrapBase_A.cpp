// All rights reserved


#include "Actors/PPTrapBase_A.h"
#include "Misc/OutputDeviceNull.h"

// Sets default values
APPTrapBase_A::APPTrapBase_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void APPTrapBase_A::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APPTrapBase_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APPTrapBase_A::TriggerTrap()
{
	//each trap overrides that 
}

void APPTrapBase_A::TryDamageActor(AActor* Actor, float PhysicalDamage, float MagicalDamage)
{
	if(Actor)
	{
		FOutputDeviceNull ar;
		const FString command = FString::Printf(TEXT("GotHitByTrap %f %f"), PhysicalDamage, MagicalDamage);
		Actor->CallFunctionByNameWithArguments(*command, ar, nullptr, true);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor is null in PPTrapBase_A"));	
	}
}

