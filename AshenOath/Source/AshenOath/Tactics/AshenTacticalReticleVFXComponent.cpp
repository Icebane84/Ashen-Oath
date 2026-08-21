// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Tactics/AshenTacticalReticleVFXComponent.h"

UAshenTacticalReticleVFXComponent::UAshenTacticalReticleVFXComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentOpacity = 0.0f;
	DesiredOpacity = 0.0f;
}

void UAshenTacticalReticleVFXComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentOpacity = FMath::FInterpTo(CurrentOpacity, DesiredOpacity, DeltaTime, 10.0f);
}

void UAshenTacticalReticleVFXComponent::SetReticleOpacity(float TargetOpacity)
{
	DesiredOpacity = FMath::Clamp(TargetOpacity, 0.0f, 1.0f);
}
