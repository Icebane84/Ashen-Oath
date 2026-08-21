// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Combat/AshenRunicVFXWeaponAdapterComponent.h"

UAshenRunicVFXWeaponAdapterComponent::UAshenRunicVFXWeaponAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentGlow = 0.0f;
	DesiredGlow = 0.0f;
}

void UAshenRunicVFXWeaponAdapterComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentGlow = FMath::FInterpTo(CurrentGlow, DesiredGlow, DeltaTime, 4.0f);
}

void UAshenRunicVFXWeaponAdapterComponent::SetRunicGlowTarget(float TargetGlow)
{
	DesiredGlow = FMath::Clamp(TargetGlow, 0.0f, 2.5f);
}
