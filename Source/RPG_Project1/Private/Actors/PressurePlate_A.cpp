// All rights reserved


#include "Actors/PressurePlate_A.h"


//#include "Components/BoxComponent.h"
//#include "Engine/Engine.h"

// Sets default values
APressurePlate_A::APressurePlate_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Component"));
	RootComponent = BoxComponent;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
	BoxComponent->SetCollisionObjectType(ECC_WorldStatic);
	BoxComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
	BoxComponent->SetBoxExtent(FVector(64.f, 64.f, 64.f));
}

// Called when the game starts or when spawned
void APressurePlate_A::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APressurePlate_A::OnComponentBeginOverlap);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this, &APressurePlate_A::OnComponentOverlapEnd);

	PrimaryActorTick.SetTickFunctionEnable(false);
	
	AscendedTargetL = GetActorLocation();
	DescendedTargetL = AscendedTargetL;
	DescendedTargetL.Z = DescendedTargetL.Z - abs(RecedeDistanceZ);
}

// Called every frame
void APressurePlate_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DirectionControl(DeltaTime);
}

//////////////////////////////////////////////

void APressurePlate_A::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
		bShouldDescend = true;
		PrimaryActorTick.SetTickFunctionEnable(true);

	//triggers all controlled traps
	for(APPTrapBase_A* Trap : ControlledTraps)
	{
		if(Trap)
		{
			Trap->TriggerTrap();
		}
	}
	//UE_LOG(LogTemp, Warning, TEXT("PressurePlate tried trigger"));
}

void APressurePlate_A::OnComponentOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	bShouldDescend = false;
	PrimaryActorTick.SetTickFunctionEnable(true);
}

void APressurePlate_A::PlateDescend(float DeltaTime)
{
	CurrentL = GetActorLocation();
	SetActorLocation(FMath::VInterpConstantTo(CurrentL, DescendedTargetL, DeltaTime, DescendInterpSpeed));
	
	if (CurrentL.Z <= DescendedTargetL.Z)
	{
		PrimaryActorTick.SetTickFunctionEnable(false);
		bShouldDescend = !bShouldDescend;
	}
}

void APressurePlate_A::PlateAscend(float DeltaTime)
{
	CurrentL = GetActorLocation();
	SetActorLocation(FMath::VInterpConstantTo(CurrentL, AscendedTargetL, DeltaTime, DescendInterpSpeed/20));

	if (CurrentL.Z >= AscendedTargetL.Z)
	{
		PrimaryActorTick.SetTickFunctionEnable(false);
		bShouldDescend = !bShouldDescend;
	}
}

void APressurePlate_A::DirectionControl(float DeltaTime)
{
	if(bShouldDescend)
	{
		PlateDescend(DeltaTime);
	}
	else
	{
		PlateAscend(DeltaTime);
	}
}






