// All rights reserved


#include "ActorComponents/CombatActions_AC.h"
#include "Interfaces/PerformCombatActions_I.h"

// Sets default values for this component's properties
UCombatActions_AC::UCombatActions_AC()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}




// Called when the game starts
void UCombatActions_AC::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCombatActions_AC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UCombatActions_AC::TryPerformAction_Implementation(ECombatActions_E Action)
{
	if(!bIsPerformingAction)
	{
		bIsPerformingAction = true;
		
		switch (Action)
		{
		case ECombatActions_E::AttackRMB:
			IPerformCombatActions_I::Execute_PerformAttackRMB(GetOwner());
			break;
			
		case ECombatActions_E::AttackLMB:
			IPerformCombatActions_I::Execute_PerformAttackLMB(GetOwner());
			break;

		case ECombatActions_E::Block:
			IPerformCombatActions_I::Execute_PerformBlock(GetOwner());
			break;

		case ECombatActions_E::Dodge:
			IPerformCombatActions_I::Execute_PerformDodge(GetOwner());
			break;
		default:
			break;
		}
	}
	else
	{
		QueuedAction = Action;
	}
	return;
}

void UCombatActions_AC::QuitPerformingAction()
{
	bIsPerformingAction = false;
	CurrentAction = ECombatActions_E::NoAction;
}
