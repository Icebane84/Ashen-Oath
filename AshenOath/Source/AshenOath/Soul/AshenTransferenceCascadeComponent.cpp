// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenTransferenceCascadeComponent.h"

UAshenTransferenceCascadeComponent::UAshenTransferenceCascadeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentStrainStage = ETransferenceStrainStage::Stable;
	AbsorbedTraumaVolume = 0.0f;
}
void UAshenTransferenceCascadeComponent::BeginPlay() { Super::BeginPlay(); }

ETransferenceStrainStage UAshenTransferenceCascadeComponent::EvaluateStrainStage(float InAbsorbedTrauma)
{
	AbsorbedTraumaVolume = FMath::Clamp(InAbsorbedTrauma, 0.0f, 1.0f);

	if (AbsorbedTraumaVolume >= 0.85f)
	{
		CurrentStrainStage = ETransferenceStrainStage::Catastrophic;
	}
	else if (AbsorbedTraumaVolume >= 0.60f)
	{
		CurrentStrainStage = ETransferenceStrainStage::Fractured;
	}
	else if (AbsorbedTraumaVolume >= 0.30f)
	{
		CurrentStrainStage = ETransferenceStrainStage::Flickering;
	}
	else
	{
		CurrentStrainStage = ETransferenceStrainStage::Stable;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenTransferenceCascadeComponent: Evaluated Strain Stage -> %d (Trauma: %.2f)"),
		static_cast<int32>(CurrentStrainStage), AbsorbedTraumaVolume);

	return CurrentStrainStage;
}
