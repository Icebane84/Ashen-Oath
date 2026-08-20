// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenDiegeticFootstepAudioResonanceComponent.h"

UAshenDiegeticFootstepAudioResonanceComponent::UAshenDiegeticFootstepAudioResonanceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenDiegeticFootstepAudioResonanceComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	FootstepWeightScalar = FMath::Clamp(1.0f + (1.0f - NewState.Resolve) * 0.8f, 0.5f, 2.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenDiegeticFootstepAudioResonanceComponent: Footstep weight scalar updated to %.2f"), FootstepWeightScalar);
}
