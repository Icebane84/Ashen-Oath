// Copyright Phoenix Protocol. All rights reserved.

#include "AshenInteractableActor.h"
#include "Components/BoxComponent.h"

AAshenInteractableActor::AAshenInteractableActor()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	RootComponent = CollisionBox;
	CollisionBox->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CollisionBox->SetGenerateOverlapEvents(true);

	InteractionText = TEXT("Interact");
	bIsOneShot = false;
	bWasUsed = false;
}

void AAshenInteractableActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenInteractableActor::Interact_Implementation(APawn* Player)
{
	if (bIsOneShot && bWasUsed)
	{
		return;
	}

	bWasUsed = true;
	OnInteracted.Broadcast(Player);
}

FString AAshenInteractableActor::GetInteractionText_Implementation() const
{
	return InteractionText;
}
