// Copyright Phoenix Protocol. All rights reserved.

#include "AshenWeaponActor.h"
#include "Components/StaticMeshComponent.h"
#include "AshenOath_HitboxComponent.h"

AAshenWeaponActor::AAshenWeaponActor()
{
	PrimaryActorTick.bCanEverTick = false;

	DefaultRoot = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultRoot"));
	RootComponent = DefaultRoot;

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	HitboxComponent = CreateDefaultSubobject<UAshenOath_HitboxComponent>(TEXT("HitboxComponent"));
	HitboxComponent->SetupAttachment(WeaponMesh);
	HitboxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	BaseDamage = 15.0f;
	PoiseDamage = 10.0f;
}

void AAshenWeaponActor::BeginPlay()
{
	Super::BeginPlay();

	if (HitboxComponent)
	{
		HitboxComponent->SetDamage(BaseDamage);
		HitboxComponent->SetPoiseDamage(PoiseDamage);
	}
}

void AAshenWeaponActor::ActivateWeapon()
{
	if (HitboxComponent)
	{
		HitboxComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

void AAshenWeaponActor::DeactivateWeapon()
{
	if (HitboxComponent)
	{
		HitboxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AAshenWeaponActor::SetWeaponTeamId(int32 TeamId)
{
	if (HitboxComponent)
	{
		HitboxComponent->SetTeamId(TeamId);
	}
}
