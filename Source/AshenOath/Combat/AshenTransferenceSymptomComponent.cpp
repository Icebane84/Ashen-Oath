// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTransferenceSymptomComponent.h"

UAshenTransferenceSymptomComponent::UAshenTransferenceSymptomComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	HandTremorIntensity = 0.0f;
	bIsCoughingBlackSap = false;
}
void UAshenTransferenceSymptomComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenTransferenceSymptomComponent::UpdateTransferenceSymptoms(float BurnoutScalar)
{
	const float B = FMath::Clamp(BurnoutScalar, 0.0f, 1.0f);
	HandTremorIntensity = (B >= 0.50f) ? (B - 0.50f) / 0.50f : 0.0f;
	bIsCoughingBlackSap = (B >= 0.65f);

	UE_LOG(LogTemp, Log, TEXT("UAshenTransferenceSymptomComponent: Burnout: %.2f -> Tremor: %.2f | Black Sap Cough: %s"),
		B, HandTremorIntensity, bIsCoughingBlackSap ? TEXT("ACTIVE") : TEXT("CLEAR"));
}
