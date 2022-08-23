// All rights reserved


#include "Actors/Bed_A.h"

#include "ActorComponents/Interactable_AC.h"

// Sets default values
ABed_A::ABed_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Tags.Add("Bed");
	SetupMeshComponent();
	SetupInteractComponent();
}

// Called when the game starts or when spawned
void ABed_A::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABed_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABed_A::GetCurrentlyUsed_Implementation(bool& State)
{
	IBed_A_I::GetCurrentlyUsed_Implementation(State);
	State = bCurrentlyUsed;
}

void ABed_A::SetCurrentlyUsed_Implementation(bool State)
{
	IBed_A_I::SetCurrentlyUsed_Implementation(State);
	bCurrentlyUsed = State;
}

///////////////////////////////////

void ABed_A::SetupInteractComponent()
{
	InteractComponent = CreateDefaultSubobject<UInteractable_AC>("Interact Component");
	//I need it so that the outline post process effect will work
	InteractComponent->PrimitiveComponent = StaticMesh;
	return;
}

void ABed_A::SetupMeshComponent()
{
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	StaticMesh->SetupAttachment(RootComponent);
	//Set objectType to Interactable
	StaticMesh->SetCollisionObjectType(ECC_GameTraceChannel1);
	//ignore all channels
	StaticMesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	//Block these:
	StaticMesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	StaticMesh->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	StaticMesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
	return;
}

