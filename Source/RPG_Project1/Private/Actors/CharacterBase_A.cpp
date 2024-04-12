// All rights reserved


#include "Actors/CharacterBase_A.h"
#include "Enums/CombatActions_E.h"
#include "ActorComponents/CombatActions_AC.h"
#include "Components/CapsuleComponent.h"
#include "Components/WidgetComponent.h"
#include "Interfaces/Chat_W_I.h"
#include "ActorComponents/Interactable_AC.h"

// Constructor
ACharacterBase_A::ACharacterBase_A()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CombatActions = CreateDefaultSubobject<UCombatActions_AC>("Combat actions component");
	ChatWidgetInitialSetup();
	CollisionInitialSetUp();
	InteractableComponentInitialSetup();
	Tags.Add("CharacterBase");
}

// Called when the game starts or when spawned
void ACharacterBase_A::BeginPlay()
{
	Super::BeginPlay();
	//ChatWidget->SetupAttachment(GetMesh());
}



// Called every frame
void ACharacterBase_A::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ACharacterBase_A::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

/** Outputs current combat action that this unit performs */
void ACharacterBase_A::GetCurrentCombatAction_Implementation(ECombatActions_E& Action)
{
	ICharacterBase_A_I::GetCurrentCombatAction_Implementation(Action);
	Action = CombatActions->CurrentAction;
}

void ACharacterBase_A::GetLocation_Implementation(FVector& Location)
{
	ICharacterBase_A_I::GetLocation_Implementation(Location);
	Location = this->GetActorLocation();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

void ACharacterBase_A::ChatWidgetInitialSetup()
{
	ChatWidget = CreateDefaultSubobject<UWidgetComponent>("ChatWidget");
	ChatWidget->SetCollisionObjectType(ECC_WorldStatic);
	ChatWidget->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ChatWidget->CanCharacterStepUpOn = ECanBeCharacterBase::ECB_No;
	ChatWidget->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	ChatWidget->SetVisibility(false, true);
	ChatWidget->SetWidgetSpace(EWidgetSpace::Screen);
	ChatWidget->SetupAttachment(GetCapsuleComponent());
	ChatWidget->SetRelativeLocation(FVector(0.0f,0.0f,GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight()));
}

void ACharacterBase_A::CollisionInitialSetUp()
{
	GetMesh()->SetGenerateOverlapEvents(false);
	GetMesh()->SetCollisionProfileName("RagDoll",false);
	GetMesh()->SetCollisionObjectType(ECC_GameTraceChannel1);
	return;
}

void ACharacterBase_A::InteractableComponentInitialSetup()
{
	InteractComponent = CreateDefaultSubobject<UInteractable_AC>("Interact Component");
	//I need it so that the outline post process effect will work
	InteractComponent->PrimitiveComponent = GetMesh();	
}

void ACharacterBase_A::ShowChatText(FText Text, EChatColour_E Colour, bool bCustomDuration, float Duration)
{
	
	if(ChatWidget->GetWidgetClass())
	{
		if(bCustomDuration)
		{
			// calls Event with custom duration
			IChat_W_I::Execute_SetChatText(ChatWidget->GetUserWidgetObject(), Text, Colour, ChatWidget, Duration);
		}
		else
		{
			// do math for automatic duration
		
			//Gets length of Incoming Text
			float TextLength = static_cast<float>(Text.ToString().Len());
			//Calls Event, with automatic Duration. Duration lasts 2 secs and + 0.1s per each character
			IChat_W_I::Execute_SetChatText(ChatWidget->GetUserWidgetObject(), Text, Colour, ChatWidget, ((TextLength * 0.1f)+2.0f));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("ChatWidget's class is not set!"));
	}
}
