// Copyright Phoenix Protocol. All rights reserved.

#include "AshenLeverActor.h"
#include "AshenDoorActor.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/World.h"

AAshenLeverActor::AAshenLeverActor()
{
	PrimaryActorTick.bCanEverTick = true;

	InteractionText = TEXT("Pull Lever");
	TargetDoor = nullptr;
	LeverAngle = 45.0f;
	TransitionDuration = 0.5f;
	bPulled = false;
	TargetAngle = -45.0f;
	CurrentAngle = -45.0f;

	HandleMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HandleMesh"));
	HandleMesh->SetupAttachment(RootComponent);
}

void AAshenLeverActor::BeginPlay()
{
	Super::BeginPlay();

	TargetAngle = bPulled ? LeverAngle : -LeverAngle;
	CurrentAngle = TargetAngle;
	HandleMesh->SetRelativeRotation(FRotator(CurrentAngle, 0.0f, 0.0f));
}

void AAshenLeverActor::Interact_Implementation(APawn* Player)
{
	Super::Interact_Implementation(Player);

	bPulled = !bPulled;
	TargetAngle = bPulled ? LeverAngle : -LeverAngle;

	if (TargetDoor)
	{
		TargetDoor->ToggleDoor();
	}

	// Play clank sound via event bus
	if (GetWorld() && GetWorld()->GetGameInstance())
	{
		UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>();
		if (EventBus)
		{
			EventBus->BroadcastSpatialSoundRequested(nullptr, GetActorLocation(), 1.0f, 1.0f);
		}
	}
}

void AAshenLeverActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentAngle != TargetAngle)
	{
		CurrentAngle = FMath::FInterpTo(CurrentAngle, TargetAngle, DeltaTime, (1.0f / TransitionDuration) * 5.0f);
		HandleMesh->SetRelativeRotation(FRotator(CurrentAngle, 0.0f, 0.0f)); // pitch rotation
	}
}
