// Copyright Phoenix Protocol. All rights reserved.

#include "AshenDoorActor.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_InventoryComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Components/SceneComponent.h"
#include "Engine/World.h"
#include "Sound/SoundBase.h"

AAshenDoorActor::AAshenDoorActor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false; // Put to sleep initially

	bIsLocked = false;
	RequiredKeyName = TEXT("Key");
	OpenAngle = 90.0f;
	TransitionDuration = 1.2f;
	bIsOpen = false;
	TargetAngle = 0.0f;
	CurrentAngle = 0.0f;
	DoorCreakSound = nullptr;

	DoorPivot = CreateDefaultSubobject<USceneComponent>(TEXT("DoorPivot"));
	DoorPivot->SetupAttachment(RootComponent);
}

void AAshenDoorActor::BeginPlay()
{
	Super::BeginPlay();
	UpdatePrompt();
}

void AAshenDoorActor::Interact_Implementation(APawn* Player)
{
	if (bIsOpen)
	{
		ToggleDoor();
		return;
	}

	if (bIsLocked)
	{
		bool bHasKey = false;
		if (Player && Player->Implements<UAshenCharacterInterface>())
		{
			if (UAshenOath_InventoryComponent* Inv = IAshenCharacterInterface::Execute_GetInventoryComponent(Player))
			{
				for (const FAshenItemData& Item : Inv->GetInventoryItems())
				{
					if (Item.ItemID == RequiredKeyName)
					{
						bHasKey = true;
						break;
					}
				}
			}
		}

		if (!bHasKey)
		{
			if (GetWorld() && GetWorld()->GetGameInstance())
			{
				UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>();
				if (EventBus)
				{
					EventBus->BroadcastInteractionHintShown(FString::Printf(TEXT("Locked: Requires %s"), *RequiredKeyName.ToString()));
				}
			}
			return;
		}
		else
		{
			bIsLocked = false;
		}
	}

	Super::Interact_Implementation(Player);
	ToggleDoor();
}

void AAshenDoorActor::ToggleDoor()
{
	bIsOpen = !bIsOpen;
	TargetAngle = bIsOpen ? OpenAngle : 0.0f;
	UpdatePrompt();

	// Wake up tick for transition interpolation
	SetActorTickEnabled(true);

	// Validate sound pointer to avoid null propagation upstream
	if (DoorCreakSound && GetWorld() && GetWorld()->GetGameInstance())
	{
		UAshenOath_GameEventSubsystem* EventBus = GetWorld()->GetGameInstance()->GetSubsystem<UAshenOath_GameEventSubsystem>();
		if (EventBus)
		{
			EventBus->BroadcastSpatialSoundRequested(DoorCreakSound, GetActorLocation(), 1.0f, 1.0f);
		}
	}
}

void AAshenDoorActor::UpdatePrompt()
{
	InteractionText = bIsOpen ? TEXT("Close Door") : (bIsLocked ? TEXT("Unlock Door (Locked)") : TEXT("Open Door"));
}

void AAshenDoorActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentAngle != TargetAngle)
	{
		CurrentAngle = FMath::FInterpTo(CurrentAngle, TargetAngle, DeltaTime, (1.0f / TransitionDuration) * 5.0f);
		DoorPivot->SetRelativeRotation(FRotator(0.0f, CurrentAngle, 0.0f)); // yaw rotation

		// Stop ticking if target is reached
		if (FMath::IsNearlyEqual(CurrentAngle, TargetAngle, 0.05f))
		{
			CurrentAngle = TargetAngle;
			DoorPivot->SetRelativeRotation(FRotator(0.0f, CurrentAngle, 0.0f));
			SetActorTickEnabled(false);
		}
	}
}
