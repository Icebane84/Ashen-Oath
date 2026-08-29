// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 677: Ashen Devils Bargain Trust Atrophy Director

#include "AshenDevilsBargainTrustAtrophyDirector.h"

void UAshenDevilsBargainTrustAtrophyDirector::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ActivePartyTrustLevel = 100.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenDevilsBargainTrustAtrophyDirector: Initialized — Trust Atrophy Director ONLINE."));
}

void UAshenDevilsBargainTrustAtrophyDirector::ApplyDevilsBargainTrustAtrophy(float AtrophyAmount)
{
	ActivePartyTrustLevel = FMath::Clamp(ActivePartyTrustLevel - AtrophyAmount, 0.0f, 100.0f);
	const float ComboDelay = (100.0f - ActivePartyTrustLevel) * 0.05f; // Delay companion combos
	const float HealingDelay = (100.0f - ActivePartyTrustLevel) * 0.08f; // Delay Serafina healing

	OnTrustAtrophyApplied.Broadcast(ActivePartyTrustLevel, ComboDelay, HealingDelay);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDevilsBargainTrustAtrophyDirector: TRUST ATROPHY APPLIED -> Remaining Trust: %.1f%% | Combo Delay: +%.2fs | Healing Delay: +%.2fs."),
		ActivePartyTrustLevel, ComboDelay, HealingDelay);
}

void UAshenDevilsBargainTrustAtrophyDirector::RestoreTrust(float RecoveryAmount)
{
	ActivePartyTrustLevel = FMath::Clamp(ActivePartyTrustLevel + RecoveryAmount, 0.0f, 100.0f);
	const float ComboDelay = (100.0f - ActivePartyTrustLevel) * 0.05f;
	const float HealingDelay = (100.0f - ActivePartyTrustLevel) * 0.08f;

	OnTrustAtrophyApplied.Broadcast(ActivePartyTrustLevel, ComboDelay, HealingDelay);

	UE_LOG(LogTemp, Log, TEXT("UAshenDevilsBargainTrustAtrophyDirector: TRUST RESTORED -> Active Trust: %.1f%%."),
		ActivePartyTrustLevel);
}
