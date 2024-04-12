// All rights reserved

#pragma once



#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/Bed_A_I.h"
#include "Bed_A.generated.h"

class UInteractable_AC;

UCLASS()
class RPG_PROJECT1_API ABed_A : public AActor, public IBed_A_I
{
	GENERATED_BODY()
	
public:	
	ABed_A();

	UPROPERTY()
	UInteractable_AC* InteractComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(BlueprintReadWrite)
	bool bCurrentlyUsed = false;
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void GetCurrentlyUsed_Implementation(bool& State) override;

	virtual void SetCurrentlyUsed_Implementation(bool State) override;
	
	//** Initial setup functions: */
private:
	UFUNCTION()
	void SetupInteractComponent();

	UFUNCTION()
	void SetupMeshComponent();
};
