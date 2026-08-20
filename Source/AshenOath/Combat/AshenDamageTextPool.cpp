// Copyright Phoenix Protocol. All rights reserved.

#include "AshenDamageTextPool.h"
#include "AshenDamageTextActor.h"
#include "Engine/World.h"
#include "AshenGameSettings.h"
#include "GameFramework/Actor.h"

UAshenDamageTextPool::UAshenDamageTextPool()
{
	PrimaryComponentTick.bCanEverTick = false;

	PoolSize = 5;
	CurrentIndex = 0;
	DamageTextClass = AAshenDamageTextActor::StaticClass();
}

void UAshenDamageTextPool::BeginPlay()
{
	Super::BeginPlay();

	// Load configuration-driven settings
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		PoolSize = Settings->DamageTextPoolSize;
	}

	if (!GetWorld() || !DamageTextClass) return;

	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = GetOwner();
	SpawnParams.Instigator = Cast<APawn>(GetOwner());
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	for (int32 i = 0; i < PoolSize; ++i)
	{
		AAshenDamageTextActor* TextActor = GetWorld()->SpawnActor<AAshenDamageTextActor>(
			DamageTextClass,
			FVector::ZeroVector,
			FRotator::ZeroRotator,
			SpawnParams
		);

		if (TextActor)
		{
			TextActor->AttachToActor(GetOwner(), FAttachmentTransformRules::KeepRelativeTransform);
			TextActor->Deactivate();
			TextPool.Add(TextActor);
		}
	}
}

void UAshenDamageTextPool::DisplayDamage(float Amount, FVector Position)
{
	if (TextPool.Num() == 0) return;

	AAshenDamageTextActor* TextActor = TextPool[CurrentIndex];
	CurrentIndex = (CurrentIndex + 1) % PoolSize;

	if (TextActor)
	{
		// Spawn slightly offset to avoid overlapping perfectly
		float OffsetRange = 50.0f;
		float HeightOffset = 120.0f;
		if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
		{
			OffsetRange = Settings->DamageTextRandomOffsetRange;
			HeightOffset = Settings->DamageTextHeightOffset;
		}

		FVector Offset = FVector(
			FMath::FRandRange(-OffsetRange, OffsetRange),
			FMath::FRandRange(-OffsetRange, OffsetRange),
			HeightOffset
		);

		TextActor->Activate(Amount, Position + Offset);
	}
}
