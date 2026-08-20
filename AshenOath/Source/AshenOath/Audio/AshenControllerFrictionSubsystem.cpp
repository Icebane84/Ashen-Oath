// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenControllerFrictionSubsystem.h"

void UAshenControllerFrictionSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentStrugglePhase = EStrugglePhase::Phase1_DiscordantHum;
	ArtificialInputDelayMilliseconds = 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenControllerFrictionSubsystem: Controller Friction Subsystem initialized."));
}
void UAshenControllerFrictionSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenControllerFrictionSubsystem::CalculateInputBufferFriction(float CorruptionAmount)
{
	const float C = FMath::Clamp(CorruptionAmount, 0.0f, 1.0f);
	// Scales input buffer latency from 0ms up to 120ms at max corruption
	ArtificialInputDelayMilliseconds = C * 120.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenControllerFrictionSubsystem: Input Buffer Friction: %.1fms (Corruption: %.2f)"),
		ArtificialInputDelayMilliseconds, C);
}

void UAshenControllerFrictionSubsystem::SetStrugglePhase(EStrugglePhase NewPhase)
{
	CurrentStrugglePhase = NewPhase;
	UE_LOG(LogTemp, Warning, TEXT("UAshenControllerFrictionSubsystem: Transitioned Struggle Phase to -> %d"),
		static_cast<int32>(CurrentStrugglePhase));
}
