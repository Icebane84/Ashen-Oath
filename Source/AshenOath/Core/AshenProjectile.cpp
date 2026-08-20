// Copyright Phoenix Protocol. All rights reserved.

#include "AshenProjectile.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/World.h"

AAshenProjectile::AAshenProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(15.0f);
	CollisionComp->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CollisionComp->SetGenerateOverlapEvents(true);
	RootComponent = CollisionComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 2000.0f;
	ProjectileMovement->MaxSpeed = 2000.0f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = false;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	ProjectileMovement->bAutoActivate = false;

	Damage = 1.0f;
	TeamId = 0;
	Lifespan = 4.0f;

	SetActorHiddenInGame(true);
}

void AAshenProjectile::Launch(const FVector& StartLocation, const FVector& Direction)
{
	GetWorldTimerManager().ClearTimer(LifespanTimerHandle);

	SetActorLocationAndRotation(StartLocation, Direction.Rotation(), false, nullptr, ETeleportType::TeleportPhysics);
	SetActorHiddenInGame(false);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	// Register overlap delegate
	CollisionComp->OnComponentBeginOverlap.AddUniqueDynamic(this, &AAshenProjectile::OnProjectileOverlap);

	if (ProjectileMovement)
	{
		ProjectileMovement->Velocity = Direction.GetSafeNormal() * ProjectileMovement->InitialSpeed;
		ProjectileMovement->Activate(true);
	}

	GetWorldTimerManager().SetTimer(LifespanTimerHandle, this, &AAshenProjectile::Deactivate, Lifespan, false);
}

void AAshenProjectile::Deactivate()
{
	GetWorldTimerManager().ClearTimer(LifespanTimerHandle);

	CollisionComp->OnComponentBeginOverlap.RemoveAll(this);
	CollisionComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	SetActorHiddenInGame(true);

	if (ProjectileMovement)
	{
		ProjectileMovement->StopMovementImmediately();
		ProjectileMovement->Deactivate();
	}
}

void AAshenProjectile::OnProjectileOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this && OtherActor != GetInstigator())
	{
		// Apply conventional damage via standard Unreal channels
		UGameplayStatics::ApplyDamage(
			OtherActor,
			Damage,
			GetInstigatorController(),
			this,
			UDamageType::StaticClass()
		);

		Deactivate();
	}
}
