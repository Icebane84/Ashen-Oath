// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenFinisherTraumaResolverComponent.h"

UAshenFinisherTraumaResolverComponent::UAshenFinisherTraumaResolverComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenFinisherTraumaResolverComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenFinisherTraumaResolverComponent::ResolveTraumaPaydown(
	EAshenPartyFinisherType FinisherType, float CurrentDebt, float CurrentBurnout)
{
	float DebtCleared = 0.0f;
	float BurnoutCleansed = 0.0f;
	float WhisperSilenceDuration = 0.0f;

	switch (FinisherType)
	{
	case EAshenPartyFinisherType::TripartiteResonantCleave:
		DebtCleared = CurrentDebt * 0.25f;
		BurnoutCleansed = CurrentBurnout * 0.35f;
		WhisperSilenceDuration = 8.0f;
		bWhispersSilenced = true;
		SilenceTimer = 8.0f;
		break;
	case EAshenPartyFinisherType::EmpathicConduitNova:
		BurnoutCleansed = CurrentBurnout; // 100% reset
		DebtCleared = CurrentDebt * 0.15f;
		WhisperSilenceDuration = 4.0f;
		break;
	case EAshenPartyFinisherType::ShepherdsIntervention:
		DebtCleared = CurrentDebt * 0.50f;
		WhisperSilenceDuration = 12.0f;
		bWhispersSilenced = true;
		SilenceTimer = 12.0f;
		break;
	default:
		DebtCleared = 10.0f;
		break;
	}

	if (OnTraumaPaydownApplied.IsBound())
	{
		OnTraumaPaydownApplied.Broadcast(DebtCleared, BurnoutCleansed, WhisperSilenceDuration);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenFinisherTraumaResolverComponent: Trauma Resolved! Debt Cleared: %.1f | Burnout Cleansed: %.1f | Whisper Silence: %.1fs"),
		DebtCleared, BurnoutCleansed, WhisperSilenceDuration);
}
