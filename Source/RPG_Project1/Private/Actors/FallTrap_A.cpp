// All rights reserved


#include "Actors/FallTrap_A.h"

//constructor
AFallTrap_A::AFallTrap_A()
{
	PrimaryActorTick.bCanEverTick = true;
	
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Mesh->SetCollisionResponseToAllChannels(ECR_Block);
}

void AFallTrap_A::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.SetTickFunctionEnable(false);

	InitialRotation = Mesh->GetComponentRotation();
	TargetRotation = InitialRotation;
	TargetRotation.Roll = TargetRotation.Roll + abs(FMath::ClampAngle(RotationDegree, 1, 90));
}

void AFallTrap_A::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	DirectionControl(DeltaSeconds);
}

/////////////////////////////////////////////

void AFallTrap_A::TriggerTrap()
{
	Super::TriggerTrap();
	if(bIsReadyToUse)
	{
		PrimaryActorTick.SetTickFunctionEnable(true);
	}
}

void AFallTrap_A::DirectionControl(float DeltaSeconds)
{
	if(bIsReadyToUse)
	{
		ThrustRotation(DeltaSeconds);
	}
	else
	{
		ReverseRotation(DeltaSeconds);
	}
}

void AFallTrap_A::ThrustRotation(float DeltaSeconds)
{
	CurrentRotation = Mesh->GetComponentRotation();
	Mesh->SetWorldRotation(FMath::RInterpConstantTo(CurrentRotation, TargetRotation, DeltaSeconds, abs(InterpSpeed)));

	if(CurrentRotation.Equals(TargetRotation, 1))
	{
		bIsReadyToUse = false;
	}
	
}

void AFallTrap_A::ReverseRotation(float DeltaSeconds)
{
	CurrentRotation = Mesh->GetComponentRotation();
	Mesh->SetWorldRotation(FMath::RInterpConstantTo(CurrentRotation,InitialRotation,DeltaSeconds,abs(InterpSpeed)/10));
	
	if(CurrentRotation.Equals(InitialRotation, 1))
	{
		bIsReadyToUse = true;
		PrimaryActorTick.SetTickFunctionEnable(false);
	}
}


