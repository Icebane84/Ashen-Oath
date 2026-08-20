// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenEnvironmentalHazardActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "GameFramework/Pawn.h"

AAshenEnvironmentalHazardActor::AAshenEnvironmentalHazardActor()
{
	PrimaryActorTick.bCanEverTick = true;

	HazardMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HazardMesh"));
	RootComponent = HazardMesh;

	HazardVolume = CreateDefaultSubobject<UBoxComponent>(TEXT("HazardVolume"));
	HazardVolume->SetupAttachment(RootComponent);
	HazardVolume->SetBoxExtent(FVector(200.0f, 200.0f, 100.0f));
	HazardVolume->SetCollisionProfileName(TEXT("Trigger"));
}

void AAshenEnvironmentalHazardActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenEnvironmentalHazardActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimerTracker += DeltaTime;
	if (TimerTracker >= 1.0f)
	{
		TimerTracker = 0.0f;
		ApplyHazardDamage();
	}
}

void AAshenEnvironmentalHazardActor::ApplyHazardDamage()
{
	if (!HazardVolume) return;

	TArray<AActor*> OverlappingActors;
	HazardVolume->GetOverlappingActors(OverlappingActors, APawn::StaticClass());

	for (AActor* Target : OverlappingActors)
	{
		if (!Target || Target == this) continue;

		if (UAshenOath_HealthComponent* Health = Target->FindComponentByClass<UAshenOath_HealthComponent>())
		{
			Health->ReceiveDamage(DamagePerSecond, this);
		}

		if (UAshenOath_PoiseComponent* Poise = Target->FindComponentByClass<UAshenOath_PoiseComponent>())
		{
			Poise->ApplyPoiseDamage(PoiseDamagePerSecond);
		}

		OnHazardDamageApplied.Broadcast(this, Target, DamagePerSecond);
		UE_LOG(LogTemp, Log, TEXT("AAshenEnvironmentalHazardActor: Hazard dealt %.0f dmg to '%s'."), DamagePerSecond, *Target->GetName());
	}
}
