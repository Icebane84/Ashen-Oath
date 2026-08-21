// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Archive/AshenRelicGlowVFXComponent.h"

UAshenRelicGlowVFXComponent::UAshenRelicGlowVFXComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentGlow = 0.0f;
	DesiredGlow = 0.0f;
}

void UAshenRelicGlowVFXComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentGlow = FMath::FInterpTo(CurrentGlow, DesiredGlow, DeltaTime, 5.0f);
}

void UAshenRelicGlowVFXComponent::SetTargetGlow(float NewGlow)
{
	DesiredGlow = FMath::Clamp(NewGlow, 0.0f, 3.0f);
}
