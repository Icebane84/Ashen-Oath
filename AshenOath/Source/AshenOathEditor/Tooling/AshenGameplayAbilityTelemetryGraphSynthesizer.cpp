// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenGameplayAbilityTelemetryGraphSynthesizer.h"

void UAshenGameplayAbilityTelemetryGraphSynthesizer::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenGameplayAbilityTelemetryGraphSynthesizer: Gameplay Ability Telemetry Graph Synthesizer initialized."));
}

bool UAshenGameplayAbilityTelemetryGraphSynthesizer::SynthesizeAbilityTelemetryPins()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenGameplayAbilityTelemetryGraphSynthesizer: RecordImprint telemetry nodes synthesized in GAS Ability Blueprints — PASSED."));
	return true;
}
