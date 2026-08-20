// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenGASTelemetryImprintBridgeComponent.h"

UAshenGASTelemetryImprintBridgeComponent::UAshenGASTelemetryImprintBridgeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGASTelemetryImprintBridgeComponent::RecordAbilityImprint(FName AbilityID, float MemoryWeight)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenGASTelemetryImprintBridgeComponent: Recorded GAS ability imprint '%s' (Weight: %.2f)"),
		*AbilityID.ToString(), MemoryWeight);
}
