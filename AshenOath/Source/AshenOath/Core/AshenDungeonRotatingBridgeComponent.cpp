// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 266: Ashen Dungeon Rotating Bridge Component

#include "AshenDungeonRotatingBridgeComponent.h"

UAshenDungeonRotatingBridgeComponent::UAshenDungeonRotatingBridgeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentAngle = 0.0f;
	TargetAlignedAngle = 180.0f;
	bIsAligned = false;
}

void UAshenDungeonRotatingBridgeComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenDungeonRotatingBridgeComponent::RotateBridge(float TargetAngleStep)
{
	CurrentAngle = FMath::Fmod(CurrentAngle + TargetAngleStep, 360.0f);
	bIsAligned = FMath::IsNearlyEqual(CurrentAngle, TargetAlignedAngle, 1.0f);

	OnBridgeRotated.Broadcast(CurrentAngle, bIsAligned);

	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonRotatingBridgeComponent: BRIDGE ROTATED to %.0f° (Aligned: %s)."),
		CurrentAngle, bIsAligned ? TEXT("TRUE") : TEXT("FALSE"));

	return bIsAligned;
}
