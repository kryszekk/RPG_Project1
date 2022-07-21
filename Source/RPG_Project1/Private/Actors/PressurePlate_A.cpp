// All rights reserved


#include "Actors/PressurePlate_A.h"

// Sets default values
APressurePlate_A::APressurePlate_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//RootComponent->CreateDefaultSubobject<USceneComponent>("RootComponent");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void APressurePlate_A::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APressurePlate_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

