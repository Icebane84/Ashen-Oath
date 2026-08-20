// Copyright Phoenix Protocol. All rights reserved.

#include "AshenProjectilePool.h"
#include "AshenProjectile.h"
#include "AshenGameSettings.h"
#include "Engine/World.h"

UAshenProjectilePool::UAshenProjectilePool()
{
	PrimaryComponentTick.bCanEverTick = false;
	PoolSize = 30;
	NextIndex = 0;
}

void UAshenProjectilePool::BeginPlay()
{
	Super::BeginPlay();

	// Load configuration-driven settings
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		PoolSize = Settings->ProjectilePoolSize;
	}

	InitializePool();
}

void UAshenProjectilePool::InitializePool()
{
	UWorld* World = GetWorld();
	if (!World || !ProjectileClass) return;

	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.Owner = GetOwner();

	for (int32 i = 0; i < PoolSize; ++i)
	{
		AAshenProjectile* Proj = World->SpawnActor<AAshenProjectile>(ProjectileClass, FVector::ZeroVector, FRotator::ZeroRotator, Params);
		if (Proj)
		{
			ProjectilePool.Add(Proj);
		}
	}
}

void UAshenProjectilePool::FireProjectile(FVector StartLocation, FVector Direction, APawn* InstigatorPawn, float ProjectileDamage, int32 ProjectileTeamId)
{
	if (ProjectilePool.Num() == 0) return;

	AAshenProjectile* Proj = ProjectilePool[NextIndex];
	NextIndex = (NextIndex + 1) % ProjectilePool.Num();

	if (Proj)
	{
		// Force deactivation to reset state safely before relaunching
		Proj->Deactivate();

		Proj->SetInstigator(InstigatorPawn);
		Proj->Damage = ProjectileDamage;
		Proj->TeamId = ProjectileTeamId;
		Proj->Launch(StartLocation, Direction);
	}
}
