// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenActiveMemoryWeavingSubsystem.h"

void UAshenActiveMemoryWeavingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentLoomPayload.ActiveThreadCount = 4;
	CurrentLoomPayload.TensionScalar = 0.0f;
	CurrentLoomPayload.PoiseAbsorptionRatio = 0.75f;
	CurrentLoomPayload.TensionState = EFilamentTensionState::Slack;
	UE_LOG(LogTemp, Log, TEXT("UAshenActiveMemoryWeavingSubsystem: Active Memory Weaving Subsystem Initialized."));
}
void UAshenActiveMemoryWeavingSubsystem::Deinitialize() { Super::Deinitialize(); }

void UAshenActiveMemoryWeavingSubsystem::CalculateWeavingDensity(float IntegrationDebt, float TrustScalar, int32& OutThreadCount, float& OutTension)
{
	const float D = FMath::Clamp(IntegrationDebt, 0.0f, 100.0f);
	const float Tr = FMath::Clamp(TrustScalar, 0.0f, 1.0f);

	// Thread count scales with Debt (1 to 8 threads)
	OutThreadCount = FMath::Clamp(FMath::RoundToInt32(1.0f + (D / 100.0f) * 7.0f), 1, 8);
	
	// Tension is high when Debt is high but Trust is low
	OutTension = FMath::Clamp((D / 100.0f) * (1.2f - Tr), 0.0f, 1.0f);

	CurrentLoomPayload.ActiveThreadCount = OutThreadCount;
	CurrentLoomPayload.TensionScalar = OutTension;

	if (OutTension >= 0.85f)
	{
		CurrentLoomPayload.TensionState = EFilamentTensionState::Snapping;
	}
	else if (OutTension >= 0.40f)
	{
		CurrentLoomPayload.TensionState = EFilamentTensionState::Tense;
	}
	else
	{
		CurrentLoomPayload.TensionState = EFilamentTensionState::Slack;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenActiveMemoryWeavingSubsystem: Threads: %d | Tension: %.2f | State: %d"),
		OutThreadCount, OutTension, static_cast<int32>(CurrentLoomPayload.TensionState));
}

bool UAshenActiveMemoryWeavingSubsystem::RegisterThreadSnapEvent()
{
	if (CurrentLoomPayload.ActiveThreadCount > 0)
	{
		CurrentLoomPayload.ActiveThreadCount--;
		UE_LOG(LogTemp, Warning, TEXT("UAshenActiveMemoryWeavingSubsystem: THREAD SNAPPED! (Remaining Threads: %d)"),
			CurrentLoomPayload.ActiveThreadCount);
		return true;
	}
	return false;
}
