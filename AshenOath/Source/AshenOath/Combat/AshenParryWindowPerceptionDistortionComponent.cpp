// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenParryWindowPerceptionDistortionComponent.h"

UAshenParryWindowPerceptionDistortionComponent::UAshenParryWindowPerceptionDistortionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenParryWindowPerceptionDistortionComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ParryVisualOffset = FMath::Clamp(NewState.Isolation * 0.15f, 0.0f, 0.20f);
	UE_LOG(LogTemp, Log, TEXT("UAshenParryWindowPerceptionDistortionComponent: Parry visual cue perception offset updated to %.3f sec"), ParryVisualOffset);
}
