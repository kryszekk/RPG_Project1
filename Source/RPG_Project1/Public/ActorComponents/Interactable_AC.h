// All rights reserved

#pragma once

// idk if I need this one below or not 
//#include <Windows.Networking.Sockets.h>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Interfaces/Interactable_AC_I.h"
#include "Interactable_AC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_PROJECT1_API UInteractable_AC : public UActorComponent, public IInteractable_AC_I
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractable_AC();

	UPROPERTY(BlueprintReadWrite)
	UPrimitiveComponent* PrimitiveComponent;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void SetRenderCustomDepth_Implementation(bool State) override;
	
};

/*	Steps to make this work with BP class
1. Attach this component to the class
2. Assign static mesh to the primitive component
3. go to static mesh details and set ObjectType to Interactables
*/