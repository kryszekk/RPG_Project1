// All rights reserved


#include "ActorComponents/Interactable_AC.h"

// Sets default values for this component's properties
UInteractable_AC::UInteractable_AC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	//TagContainer.AddTag(FGameplayTag::RequestGameplayTag(FName("Interactable")));
	this->UActorComponent::ComponentTags.Add("Interactable");
	// ...
}


// Called when the game starts
void UInteractable_AC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInteractable_AC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

void UInteractable_AC::SetRenderCustomDepth_Implementation(bool State)
{
	PrimitiveComponent->SetRenderCustomDepth(State);
}


