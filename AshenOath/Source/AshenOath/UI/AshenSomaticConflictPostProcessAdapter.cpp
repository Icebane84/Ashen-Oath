// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenSomaticConflictPostProcessAdapter.h"

UAshenSomaticConflictPostProcessAdapter::UAshenSomaticConflictPostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	MaxChromaticAberration = 3.5f;
	MaxVignetteIntensity = 0.85f;
	InterpSpeed = 5.0f;
	CurrentChromaticAberration = 0.0f;
	TargetChromaticAberration = 0.0f;
	CurrentVignette = 0.2f;
	TargetVignette = 0.2f;
}

void UAshenSomaticConflictPostProcessAdapter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentChromaticAberration = FMath::FInterpTo(CurrentChromaticAberration, TargetChromaticAberration, DeltaTime, InterpSpeed);
	CurrentVignette = FMath::FInterpTo(CurrentVignette, TargetVignette, DeltaTime, InterpSpeed);
}

void UAshenSomaticConflictPostProcessAdapter::UpdateFrictionPostProcess(float InternalFriction)
{
	const float ClampedFriction = FMath::Clamp(InternalFriction, 0.0f, 1.0f);
	TargetChromaticAberration = ClampedFriction * MaxChromaticAberration;
	TargetVignette = FMath::Lerp(0.20f, MaxVignetteIntensity, ClampedFriction);
}
