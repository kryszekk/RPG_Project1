// All rights reserved


#include "Actors/LeverDoor_A.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
ALeverDoor_A::ALeverDoor_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned 
void ALeverDoor_A::BeginPlay()
{
	Super::BeginPlay();
	
	//Only BP_Lever should enable tick by calling TriggerDoor();
	//This way TickFunction is only active when it is essential for Interpolation,
	//after door is finished with interpolation (reached Target location) 
	//the Tick function is disabled as it's no longer essential.
	PrimaryActorTick.SetTickFunctionEnable(false);
	
	TargetCloseL = GetActorLocation();
	TargetOpenL = TargetCloseL;
	TargetOpenL.Z = TargetOpenL.Z + TargetDistanceZ;
}

// Called every frame
void ALeverDoor_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OpenOrClose(DeltaTime);
}

//Implementations
void ALeverDoor_A::Open(float DeltaTime)
{
	CurrentL =GetActorLocation();
	SetActorLocation(FMath::VInterpConstantTo(CurrentL, TargetOpenL, DeltaTime, InterpSpeed)); 

	//When opening finishes
	if(CurrentL.Z >= TargetOpenL.Z)
	{
		//Next Interpolation should close door
		bShouldOpen = false;
		//Turns off tick. Lever class will turn it back on when it's interacted with
		PrimaryActorTick.SetTickFunctionEnable(false);
	}
	return;
}

void ALeverDoor_A::Close(float DeltaTime)
{
	CurrentL = GetActorLocation();
	SetActorLocation(FMath::VInterpConstantTo(CurrentL, TargetCloseL, DeltaTime, InterpSpeed));
	if(CurrentL.Z <= TargetCloseL.Z)
	{
		//Next Interpolation should open door
		bShouldOpen = true;
		//Turns off tick. Lever class will turn it back on when it's interacted with 
		PrimaryActorTick.SetTickFunctionEnable(false);
	}
	return;
}

void ALeverDoor_A::OpenOrClose(float DeltaTime)
{//Determines whether door should open or close right after the lever is triggered
	if(bShouldOpen)
		{ Open(DeltaTime); }
	else
		{ Close(DeltaTime); }
}

void ALeverDoor_A::TriggerDoor()
{
	//Basically it only turns ON ticking then FOpenOrClose(); decides if the doors should open or close
	//after which the tick will be turn off, waiting to be turn ON by calling this function again
	
	// When door is CLOSED and FTriggerDoor(); will be called the door will OPEN after which it will disable tick
	// when door is OPEN and FTriggerDoor(); will be called the door will CLOSE after which it will disable tick
	PrimaryActorTick.SetTickFunctionEnable(true);
}
