// Copyright Phoenix Protocol. All rights reserved.

#include "AshenChestActor.h"
#include "AshenOath_LootComponent.h"
#include "Components/StaticMeshComponent.h"

AAshenChestActor::AAshenChestActor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false; // Put to sleep initially

	InteractionText = TEXT("Open Chest");
	bIsOneShot = true;

	LidMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LidMesh"));
	LidMesh->SetupAttachment(RootComponent);

	LootComponent = CreateDefaultSubobject<UAshenOath_LootComponent>(TEXT("LootComponent"));

	OpenAngle = -90.0f; // rotate lid backward
	OpenDuration = 1.0f;
	bIsOpen = false;
	TargetAngle = 0.0f;
	CurrentAngle = 0.0f;
}

void AAshenChestActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenChestActor::Interact_Implementation(APawn* Player)
{
	if (bIsOpen) return;

	Super::Interact_Implementation(Player);

	bIsOpen = true;
	TargetAngle = OpenAngle;

	// Wake up tick for transition interpolation
	SetActorTickEnabled(true);

	if (LootComponent)
	{
		LootComponent->SpawnLoot();
	}
}

void AAshenChestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsOpen && CurrentAngle != TargetAngle)
	{
		// Smoothly rotate the lid mesh
		CurrentAngle = FMath::FInterpTo(CurrentAngle, TargetAngle, DeltaTime, (1.0f / OpenDuration) * 5.0f);
		LidMesh->SetRelativeRotation(FRotator(CurrentAngle, 0.0f, 0.0f)); // pitch rotation

		// Stop ticking if target is reached
		if (FMath::IsNearlyEqual(CurrentAngle, TargetAngle, 0.05f))
		{
			CurrentAngle = TargetAngle;
			LidMesh->SetRelativeRotation(FRotator(CurrentAngle, 0.0f, 0.0f));
			SetActorTickEnabled(false);
		}
	}
}
