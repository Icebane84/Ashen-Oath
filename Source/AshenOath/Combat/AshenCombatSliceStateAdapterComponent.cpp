// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenCombatSliceStateAdapterComponent.h"
#include "Soul/AshenBehavioralProfileDerivationEngine.h"

UAshenCombatSliceStateAdapterComponent::UAshenCombatSliceStateAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCombatSliceStateAdapterComponent::SubmitCombatImprint(float FailureWeight)
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCombatSliceStateAdapterComponent: Combat slice submitting imprint (Weight: %.2f)"), FailureWeight);
}

void UAshenCombatSliceStateAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	FBehavioralProfile Profile = UAshenBehavioralProfileDerivationEngine::DeriveBehavioralProfile(NewState);
	switch (Profile.Stance)
	{
	case EStanceProfile::Hunched_Guarded:
		CombatStanceWeight = 1.0f;
		break;
	case EStanceProfile::Upright_Grounded:
		CombatStanceWeight = 0.0f;
		break;
	case EStanceProfile::Balanced_Steady:
	default:
		CombatStanceWeight = 0.5f;
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenCombatSliceStateAdapterComponent: Combat stance weight updated to %.2f"), CombatStanceWeight);
}
