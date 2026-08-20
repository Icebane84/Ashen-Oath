// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSolarBeaconActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenVFXPoolSubsystem.h"
#include "GameFramework/Pawn.h"

AAshenSolarBeaconActor::AAshenSolarBeaconActor()
{
	PrimaryActorTick.bCanEverTick = true;

	BeaconMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BeaconMesh"));
	RootComponent = BeaconMesh;

	WardVolume = CreateDefaultSubobject<USphereComponent>(TEXT("WardVolume"));
	WardVolume->SetupAttachment(RootComponent);
	WardVolume->SetSphereRadius(500.0f);
	WardVolume->SetCollisionProfileName(TEXT("Trigger"));

	HealAmountPerPulse = 40.0f;
	HolyDamagePerPulse = 50.0f;
	PulseInterval = 3.0f;
}

void AAshenSolarBeaconActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenSolarBeaconActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TimerTracker += DeltaTime;
	if (TimerTracker >= PulseInterval)
	{
		TimerTracker = 0.0f;
		ExecuteHolyPulse();
	}
}

void AAshenSolarBeaconActor::ExecuteHolyPulse()
{
	if (!WardVolume) return;

	TArray<AActor*> OverlappingActors;
	WardVolume->GetOverlappingActors(OverlappingActors, APawn::StaticClass());

	int32 HealedAllies = 0;
	int32 DamagedEnemies = 0;

	for (AActor* Target : OverlappingActors)
	{
		if (!Target || Target == this) continue;

		if (UAshenOath_HealthComponent* Health = Target->FindComponentByClass<UAshenOath_HealthComponent>())
		{
			if (Target->ActorHasTag(FName("Player")) || Target->ActorHasTag(FName("Companion")))
			{
				Health->Heal(HealAmountPerPulse);
				HealedAllies++;
			}
			else
			{
				Health->ReceiveDamage(HolyDamagePerPulse, this);
				DamagedEnemies++;
			}
		}
	}

	if (GetWorld())
	{
		if (UAshenVFXPoolSubsystem* VFXPool = GetWorld()->GetSubsystem<UAshenVFXPoolSubsystem>())
		{
			VFXPool->SpawnPooledVFX(FName("VFX_SolarBeaconPulse"), GetActorLocation(), FRotator::ZeroRotator);
		}
	}

	OnPulseExecuted.Broadcast(HealedAllies, DamagedEnemies);
	UE_LOG(LogTemp, Log, TEXT("AAshenSolarBeaconActor: Holy pulse executed (%d allies healed, %d enemies damaged)."), HealedAllies, DamagedEnemies);
}
