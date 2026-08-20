// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 574: Ashen Whispering Winds Oracle Subsystem

#include "AshenWhisperingWindsOracleSubsystem.h"

void UAshenWhisperingWindsOracleSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenWhisperingWindsOracleSubsystem: Initialized — Whispering Winds Oracle Subsystem ONLINE."));
}

void UAshenWhisperingWindsOracleSubsystem::EvaluateOracleHint(FName OracleHintID, float SanityPercent)
{
	const float TruthClarity = FMath::Clamp(SanityPercent, 10.0f, 100.0f);
	OnOracleHintEvaluated.Broadcast(OracleHintID, TruthClarity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWhisperingWindsOracleSubsystem: ORACLE HINT EVALUATED -> Hint '%s' (Truth Clarity: %.1f%%)."),
		*OracleHintID.ToString(), TruthClarity);
}
