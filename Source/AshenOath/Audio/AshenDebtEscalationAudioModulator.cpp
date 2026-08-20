// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Audio/AshenDebtEscalationAudioModulator.h"

UAshenDebtEscalationAudioModulator::UAshenDebtEscalationAudioModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenDebtEscalationAudioModulator::BeginPlay() { Super::BeginPlay(); }

void UAshenDebtEscalationAudioModulator::UpdateAudioModulationForDebtStage(EAshenIntegrationDebtStage Stage)
{
	switch (Stage)
	{
	case EAshenIntegrationDebtStage::MemoryBleed:
		WhisperSpawnFrequency = 2.0f; // Doubles whisper spawn frequency per ENGINE-SPEC-001
		PitchVarianceMultiplier = 1.25f;
		break;
	case EAshenIntegrationDebtStage::RuntimeNoise:
		WhisperSpawnFrequency = 3.5f;
		PitchVarianceMultiplier = 1.60f;
		break;
	case EAshenIntegrationDebtStage::ForcedCollapse:
		WhisperSpawnFrequency = 5.0f;
		PitchVarianceMultiplier = 2.0f;
		break;
	default:
		WhisperSpawnFrequency = 1.0f;
		PitchVarianceMultiplier = 1.0f;
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenDebtEscalationAudioModulator: Audio modulated for debt stage %d — WhisperFreq=%f PitchMultiplier=%f"),
		(int32)Stage, WhisperSpawnFrequency, PitchVarianceMultiplier);
}
