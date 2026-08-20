// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 589: Ashen Boss Death Cinematic Director Subsystem

#include "AshenBossDeathCinematicDirectorSubsystem.h"
#include "GameFramework/Actor.h"

void UAshenBossDeathCinematicDirectorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenBossDeathCinematicDirectorSubsystem: Initialized — Boss Death Cinematic Director ONLINE."));
}

void UAshenBossDeathCinematicDirectorSubsystem::TriggerBossDeathCinematic(AActor* BossActor, float TimeDilation)
{
	if (!BossActor) return;

	OnBossDeathCinematic.Broadcast(BossActor, TimeDilation);

	UE_LOG(LogTemp, Warning, TEXT("UAshenBossDeathCinematicDirectorSubsystem: BOSS DEATH CINEMATIC TRIGGERED -> Boss '%s' | Time Dilation: %.2fx."),
		*BossActor->GetName(), TimeDilation);
}
