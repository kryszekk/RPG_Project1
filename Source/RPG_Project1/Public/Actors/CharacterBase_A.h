// All rights reserved

#pragma once

#include "Interfaces/CharacterBase_A_I.h"
#include "Enums/ChatColour_E.h"

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CharacterBase_A.generated.h"

//forward declarations:
class UCombatActions_AC;
class UWidgetComponent;
class UInteractable_AC;


UCLASS()
class RPG_PROJECT1_API ACharacterBase_A : public ACharacter, public ICharacterBase_A_I
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACharacterBase_A();

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UWidgetComponent* ChatWidget;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ShowChatText(FText Text, EChatColour_E Colour, bool bCustomDuration, float Duration);

	UPROPERTY()
	UCombatActions_AC* CombatActions;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Outputs current combat action that this unit performs */
	virtual void GetCurrentCombatAction_Implementation(ECombatActions_E& Action) override;

	/** Returns Vector of player's location */
	virtual void GetLocation_Implementation(FVector& Location) override;

private:
	UFUNCTION()
	void ChatWidgetInitialSetup();

	UFUNCTION()
	void CollisionInitialSetUp();

	UFUNCTION()
	void InteractableComponentInitialSetup();

	UPROPERTY()
	UInteractable_AC* InteractComponent;
};
