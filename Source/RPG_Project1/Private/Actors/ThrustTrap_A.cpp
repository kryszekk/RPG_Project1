// All rights reserved


#include "Actors/ThrustTrap_A.h"


//constructor
AThrustTrap_A::AThrustTrap_A()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root Component");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
}

void AThrustTrap_A::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.SetTickFunctionEnable(false);

	Mesh->OnComponentHit.AddDynamic(this, &AThrustTrap_A::OnComponentHit);
	
	InitialLocation = Mesh->GetComponentLocation();
	ThrustTargetLocation = InitialLocation;
	ThrustTargetLocation  = InitialLocation + (Mesh->GetForwardVector() * abs(ThrustDistance));
}

void AThrustTrap_A::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	DirectionControl(DeltaSeconds);
}

void AThrustTrap_A::TriggerTrap()
{
	Super::TriggerTrap();
	if(bIsReadyToUse)
	{
		PrimaryActorTick.SetTickFunctionEnable(true);
	}
}

void AThrustTrap_A::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if(bIsThrusting)
	{
		if(!HitActors.Contains(OtherActor))	//So any actor gets hit only once per trap swing/thrust.
		{
			TryDamageActor(OtherActor, TrapPhysicalDMG, TrapMagicalDMG);
			HitActors.Add(OtherActor);
		}
	}	
	else
	{
	//	UE_LOG(LogTemp, Display, TEXT("ThrustTrap has just hit an actor but it's in Reverse so no damage dealt"));
	}
}

void AThrustTrap_A::DirectionControl(float DeltaTime)
{
	if(bIsReadyToUse)
	{
		Thrust(DeltaTime);	
	}
	else
	{
		Reverse(DeltaTime);
	}
}

void AThrustTrap_A::Thrust(float DeltaTime)
{
	bIsThrusting = true;
	CurrentLocation = Mesh->GetComponentLocation();
	Mesh->SetWorldLocation(FMath::VInterpConstantTo(CurrentLocation, ThrustTargetLocation, DeltaTime, abs(InterpSpeed)));
	
	//Do when Trap reaches target location
	if(CurrentLocation.Equals(ThrustTargetLocation, 1))
	{
		bIsReadyToUse = false;
		bIsThrusting = false;
	}
}

void AThrustTrap_A::Reverse(float DeltaTime)
{
	CurrentLocation = Mesh->GetComponentLocation();
	Mesh->SetWorldLocation(FMath::VInterpConstantTo(CurrentLocation, InitialLocation, DeltaTime, abs(InterpSpeed/10)));

	//Do when trap gets back to initial location
	if (CurrentLocation.Equals(InitialLocation, 1))
	{
		bIsReadyToUse = true;
		PrimaryActorTick.SetTickFunctionEnable(false);
		HitActors.Empty();	//Clears list of hit actors so they can get hit again with a new trap's swing/thrust.
		
	}
}
