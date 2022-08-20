// All rights reserved


#include "Actors/FastTravelSpot_A.h"
#include "ActorComponents/Interactable_AC.h"

// Sets default values
AFastTravelSpot_A::AFastTravelSpot_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Tags.Add("FastTravelSpot");
	
	
	RootComponent= CreateDefaultSubobject<USceneComponent>("Root");
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Static Mesh");
	Mesh-> SetupAttachment(RootComponent);
	
	InteractComponent = CreateDefaultSubobject<UInteractable_AC>("Interact Component");
	//I need it so that the outline post process effect will work
	InteractComponent->PrimitiveComponent = Mesh;
	
///////////////////////////////////////COLLISION/////////////////////////////////////////////
	//My "Interactable" collision channel is ECC_GameTraceChannel1
	Mesh->SetCollisionObjectType(ECC_GameTraceChannel1);

	//ignore all channels
	Mesh->SetCollisionResponseToAllChannels(ECR_Ignore);
	//Block these:
	Mesh->SetCollisionResponseToChannel(ECC_WorldStatic, ECR_Block);
	Mesh->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Block);
	Mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Block);
}

// Called when the game starts or when spawned
void AFastTravelSpot_A::BeginPlay()
{
	Super::BeginPlay();

	//Set Default Target spot	to +100 in X axis
	if(!bCustomTargetSpot)
	{
		TargetSpot = GetActorTransform();
		TargetSpot.SetLocation(FVector(TargetSpot.GetLocation().X + 200, TargetSpot.GetLocation().Y, TargetSpot.GetLocation().Z ));
	}
}

// Called every frame
void AFastTravelSpot_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


void AFastTravelSpot_A::GetIsDiscovered_Implementation(bool& state)
{
	state = bIsDiscovered;
}

void AFastTravelSpot_A::SetIsDiscovered_Implementation(bool state)
{
	bIsDiscovered = state;
}
