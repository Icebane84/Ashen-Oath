// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 166: Ashen Respawn Subsystem

#include "AshenRespawnSubsystem.h"
#include "GameFramework/Pawn.h"
#include "Engine/World.h"
#include "TimerManager.h"

void UAshenRespawnSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActiveSanctuaryLocation = FVector::ZeroVector;
	UE_LOG(LogTemp, Log, TEXT("UAshenRespawnSubsystem: Initialized — awaiting sanctuary registration."));
}

void UAshenRespawnSubsystem::RegisterSanctuaryLocation(FVector SanctuaryLocation)
{
	ActiveSanctuaryLocation = SanctuaryLocation;
	UE_LOG(LogTemp, Warning, TEXT("UAshenRespawnSubsystem: Sanctuary registered at (%.0f, %.0f, %.0f)."),
		SanctuaryLocation.X, SanctuaryLocation.Y, SanctuaryLocation.Z);
}

void UAshenRespawnSubsystem::TriggerPlayerDeath(APawn* DeadPawn)
{
	if (!DeadPawn)
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenRespawnSubsystem: TriggerPlayerDeath called with null pawn."));
		return;
	}

	if (ActiveSanctuaryLocation.IsZero())
	{
		UE_LOG(LogTemp, Error, TEXT("UAshenRespawnSubsystem: No sanctuary registered — cannot respawn."));
		return;
	}

	PendingRespawnPawn = DeadPawn;

	UE_LOG(LogTemp, Warning, TEXT("UAshenRespawnSubsystem: Player '%s' DIED — scheduling respawn in %.1fs at sanctuary."),
		*DeadPawn->GetName(), RespawnFadeDelay);

	GetWorld()->GetTimerManager().SetTimer(
		RespawnTimerHandle,
		this,
		&UAshenRespawnSubsystem::ExecuteRespawn,
		RespawnFadeDelay,
		false
	);
}

void UAshenRespawnSubsystem::ExecuteRespawn()
{
	APawn* Pawn = PendingRespawnPawn.Get();
	if (!Pawn) return;

	Pawn->SetActorLocation(ActiveSanctuaryLocation);
	OnPlayerRespawned.Broadcast(ActiveSanctuaryLocation);

	UE_LOG(LogTemp, Warning, TEXT("UAshenRespawnSubsystem: Player RESPAWNED at sanctuary (%.0f, %.0f, %.0f)."),
		ActiveSanctuaryLocation.X, ActiveSanctuaryLocation.Y, ActiveSanctuaryLocation.Z);
}
