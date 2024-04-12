// All rights reserved

#pragma once

#include "Enums/CombatActions_E.h"
#include "Interfaces/CombatActions_AC_I.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"	//Can I get rid of this include?
#include "CombatActions_AC.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RPG_PROJECT1_API UCombatActions_AC : public UActorComponent, public ICombatActions_AC_I
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UCombatActions_AC();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECombatActions_E CurrentAction = ECombatActions_E::NoAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ECombatActions_E QueuedAction = ECombatActions_E::NoAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsPerformingAction;

	////////////////////////////////////////////////////////
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void TryPerformAction(ECombatActions_E Action);

	UFUNCTION()
	void QuitPerformingAction();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
		
};
