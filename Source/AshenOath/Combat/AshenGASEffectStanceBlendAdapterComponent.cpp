// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGASEffectStanceBlendAdapterComponent.h"

UAshenGASEffectStanceBlendAdapterComponent::UAshenGASEffectStanceBlendAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGASEffectStanceBlendAdapterComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	StanceAggressionWeight = FMath::Clamp((NewState.Corruption * 0.6f) + (NewState.Resolve * 0.4f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGASEffectStanceBlendAdapterComponent: Stance aggression weight updated to %.2f"), StanceAggressionWeight);
}
