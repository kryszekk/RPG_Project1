// All rights reserved


#include "Actors/PPTrapBase_A.h"

#include "ActorComponents/PlayerAttributes_AC.h"
#include "ActorComponents/SimpleAttributes_AC.h"
#include "Interfaces/AIBase_A_I.h"
#include "Interfaces/AttributesBase_AC_I.h"
#include "Interfaces/Player_A_I.h"

// Sets default values
APPTrapBase_A::APPTrapBase_A()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void APPTrapBase_A::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APPTrapBase_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void APPTrapBase_A::TriggerTrap()
{
	//each trap overrides that 
}

void APPTrapBase_A::TryDamageActor(AActor* Actor, float PhysicalDamage, float MagicalDamage)
{
	if(Actor)
	{
		if(Actor->ActorHasTag("Player"))
		{
			UPlayerAttributes_AC* PAttributesComponent;
			IPlayer_A_I::Execute_GetPlayerAttributesComponent(Actor, PAttributesComponent);
			IAttributesBase_AC_I::Execute_TryGetHitByEnemy(PAttributesComponent, PhysicalDamage, MagicalDamage);
		}
		else if (Actor->ActorHasTag("AI_Base"))
		{
			USimpleAttributes_AC* SAttributesComponent;
			IAIBase_A_I::Execute_GetSimpleAttributeComponent(Actor, SAttributesComponent);
			IAttributesBase_AC_I::Execute_TryGetHitByEnemy(SAttributesComponent, PhysicalDamage, MagicalDamage);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Actor is null in PPTrapBase_A"));	
	}
}

