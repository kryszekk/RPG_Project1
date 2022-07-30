// All rights reserved


#include "Actors/RotatingTrap_A.h"

#include <string>

//Constructor
ARotatingTrap_A::ARotatingTrap_A()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Mesh->SetCollisionObjectType(ECC_WorldDynamic);
	Mesh->SetCollisionResponseToAllChannels(ECR_Block);
	Mesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	
}

void ARotatingTrap_A::BeginPlay()
{
	Super::BeginPlay();
	PrimaryActorTick.SetTickFunctionEnable(false);
	
	Mesh->OnComponentHit.AddDynamic(this, &ARotatingTrap_A::OnComponentHit);

	InitialRotation = Mesh->GetComponentRotation();
	TargetRotation = InitialRotation;
	TargetRotation.Yaw = TargetRotation.Yaw + abs(FMath::ClampAngle(RotationDegree,1,179));
}

void ARotatingTrap_A::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	DirectionControl(DeltaSeconds);
}



void ARotatingTrap_A::OnComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	if(bIsThrusting)
	{
		if(!HitActors.Contains(OtherActor))
		{
			TryDamageActor(OtherActor, TrapPhysicalDMG, TrapMagicalDMG);
			HitActors.Add(OtherActor);
		}
	}
	else
	{
		//UE_LOG(LogTemp, Display, TEXT("RotatingTrap has just hit an actor but it's in Reverse so no damage dealt"));
	}
}

void ARotatingTrap_A::DirectionControl(float DeltaSeconds)
{
	if(bIsReadyToUse)
	{
		Swing(DeltaSeconds);
	}
	else
	{
		Reverse(DeltaSeconds);
	}
}

void ARotatingTrap_A::Reverse(float DeltaSeconds)
{
	CurrentRotation = Mesh->GetComponentRotation();
	Mesh->SetWorldRotation( FMath::RInterpConstantTo(CurrentRotation,InitialRotation,DeltaSeconds, abs(InterpSpeed)/10));
	
	if(CurrentRotation.Equals(InitialRotation,1))
	{
		PrimaryActorTick.SetTickFunctionEnable(false);
		bIsReadyToUse = true;
		
		HitActors.Empty();	//Clears list of hit actors so they can get hit again with a new trap's swing/thrust.
	}
}

void ARotatingTrap_A::Swing(float DeltaSeconds)
{
	bIsThrusting = true;	//Can damage actor
	
	CurrentRotation = Mesh->GetComponentRotation();
	Mesh->SetWorldRotation(FMath::RInterpConstantTo(CurrentRotation,TargetRotation,DeltaSeconds, abs(InterpSpeed))); 
	
	if (CurrentRotation.Equals(TargetRotation, 1))
	{
		bIsReadyToUse = false;
		bIsThrusting = false;	// No longer can damage actor
	}
}

void ARotatingTrap_A::TriggerTrap()
{
	Super::TriggerTrap();

	if(bIsReadyToUse)
	{
		PrimaryActorTick.SetTickFunctionEnable(true);
	}
}



