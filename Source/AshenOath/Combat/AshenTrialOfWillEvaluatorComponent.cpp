// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTrialOfWillEvaluatorComponent.h"

UAshenTrialOfWillEvaluatorComponent::UAshenTrialOfWillEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	LastChoice = ETrialOfWillChoice::None;
}
void UAshenTrialOfWillEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenTrialOfWillEvaluatorComponent::EvaluateStaggerChoice(ETrialOfWillChoice Choice, float& OutDebtDelta, float& OutCorruptionDelta, float& OutTrustDelta)
{
	LastChoice = Choice;
	OutDebtDelta = 0.0f;
	OutCorruptionDelta = 0.0f;
	OutTrustDelta = 0.0f;

	switch (Choice)
	{
	case ETrialOfWillChoice::Defiance:
		OutDebtDelta = 2.5f;        // +2.5 debt
		OutCorruptionDelta = 0.0f;
		OutTrustDelta = -1.0f;       // Slight isolation
		UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillEvaluatorComponent: Chosen DEFIANCE (Blade Plant) -> Debt +2.5"));
		break;
	case ETrialOfWillChoice::Wrath:
		OutDebtDelta = 0.0f;
		OutCorruptionDelta = 5.0f;  // +5.0 taint
		OutTrustDelta = -2.0f;       // Hostile volatility
		UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillEvaluatorComponent: Chosen WRATH (Necrotic Slam) -> Taint +5.0"));
		break;
	case ETrialOfWillChoice::Trust:
		OutDebtDelta = -5.0f;       // Clears 5% debt
		OutCorruptionDelta = 0.0f;
		OutTrustDelta = 3.5f;        // +3.5 trust
		UE_LOG(LogTemp, Warning, TEXT("UAshenTrialOfWillEvaluatorComponent: Chosen TRUST (Bulwark Fallback) -> Trust +3.5, Debt -5%%"));
		break;
	default:
		break;
	}
}
