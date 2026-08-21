// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Haptics/AshenControllerVibrationAdapterComponent.h"

UAshenControllerVibrationAdapterComponent::UAshenControllerVibrationAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	CurrentLeft = 0.0f;
	CurrentRight = 0.0f;
	DesiredLeft = 0.0f;
	DesiredRight = 0.0f;
}

void UAshenControllerVibrationAdapterComponent::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	CurrentLeft = FMath::FInterpTo(CurrentLeft, DesiredLeft, DeltaTime, 8.0f);
	CurrentRight = FMath::FInterpTo(CurrentRight, DesiredRight, DeltaTime, 8.0f);
}

void UAshenControllerVibrationAdapterComponent::SetTargetVibration(float LeftMotor, float RightMotor)
{
	DesiredLeft = FMath::Clamp(LeftMotor, 0.0f, 1.0f);
	DesiredRight = FMath::Clamp(RightMotor, 0.0f, 1.0f);
}
