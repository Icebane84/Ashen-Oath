// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 803: Ashen Devil's Bargain Chilling Silence Subsystem

#include "AshenDevilsBargainChillingSilenceSubsystem.h"

void UAshenDevilsBargainChillingSilenceSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	bIsChillingSilenceActive = false;
	UE_LOG(LogTemp, Log, TEXT("UAshenDevilsBargainChillingSilenceSubsystem: Initialized — Chilling Silence Protocol Subsystem ONLINE."));
}

void UAshenDevilsBargainChillingSilenceSubsystem::EvaluateChillingSilenceProtocol(int32 TotalSurrendersToDarkMode)
{
	bIsChillingSilenceActive = (TotalSurrendersToDarkMode >= 3);
	const FText Whisper = bIsChillingSilenceActive ? FText::FromString(TEXT("Thank you.")) : FText::FromString(TEXT("Surrender to the White Flame's shade..."));

	OnChillingSilenceStateChanged.Broadcast(bIsChillingSilenceActive, Whisper);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDevilsBargainChillingSilenceSubsystem: CHILLING SILENCE EVALUATED -> Dark Surrenders: %d | Chilling Silence: %s | Whisper: '%s'."),
		TotalSurrendersToDarkMode, bIsChillingSilenceActive ? TEXT("TRUE (Vacuum Active)") : TEXT("FALSE"), *Whisper.ToString());
}
