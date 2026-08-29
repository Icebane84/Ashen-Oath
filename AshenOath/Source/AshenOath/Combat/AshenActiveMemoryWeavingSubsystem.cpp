// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenActiveMemoryWeavingSubsystem.h"
#include "Combat/AshenOath_SanityComponent.h"

void UAshenActiveMemoryWeavingSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	CurrentLoomPayload.ActiveThreadCount = 4;
	CurrentLoomPayload.TensionScalar = 0.20f;
	CurrentLoomPayload.TensionState = EFilamentTensionState::Slack;
	UE_LOG(LogTemp, Log, TEXT("UAshenActiveMemoryWeavingSubsystem: Active Memory Weaving Subsystem Initialized."));
}

void UAshenActiveMemoryWeavingSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

void UAshenActiveMemoryWeavingSubsystem::CalculateWeavingDensity(
	float IntegrationDebt,
	float TrustScalar,
	int32& OutThreadCount,
	float& OutTension)
{
	// Threads scale with mutual trust: 4..20 threads
	OutThreadCount = FMath::Clamp(FMath::RoundToInt(4.0f + TrustScalar * 16.0f), 2, 24);

	// Tension scales with unintegrated trauma/debt: 0.20..1.00
	OutTension = FMath::Clamp(0.20f + IntegrationDebt * 0.80f, 0.0f, 1.0f);

	CurrentLoomPayload.ActiveThreadCount = OutThreadCount;
	CurrentLoomPayload.TensionScalar = OutTension;
	CurrentLoomPayload.TensionState = (OutTension > 0.80f) ? EFilamentTensionState::Snapping : (OutTension > 0.40f ? EFilamentTensionState::Tense : EFilamentTensionState::Slack);

	if (OnWeavingDensityUpdated.IsBound())
	{
		OnWeavingDensityUpdated.Broadcast(OutThreadCount, OutTension);
	}
}

bool UAshenActiveMemoryWeavingSubsystem::RegisterThreadSnapEvent(AActor* KaelenActor)
{
	if (CurrentLoomPayload.TensionScalar < 0.80f)
	{
		return false; // Tension not high enough to snap
	}

	const float SanityBacklash = 15.0f;
	if (KaelenActor)
	{
		if (UAshenOath_SanityComponent* SanityComp = KaelenActor->FindComponentByClass<UAshenOath_SanityComponent>())
		{
			SanityComp->SufferMentalDamage(SanityBacklash);
		}
	}

	CurrentLoomPayload.ActiveThreadCount = FMath::Max(2, CurrentLoomPayload.ActiveThreadCount - 2);
	CurrentLoomPayload.TensionState = EFilamentTensionState::Slack;

	if (OnThreadSnapped.IsBound())
	{
		OnThreadSnapped.Broadcast(SanityBacklash);
	}

	UE_LOG(LogTemp, Error, TEXT("UAshenActiveMemoryWeavingSubsystem: *** MEMORY WEAVE THREAD SNAPPED *** (Inflicted %.1f Sanity Backlash)!"),
		SanityBacklash);

	return true;
}
