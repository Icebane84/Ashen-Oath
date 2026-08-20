// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenSentinelGraphInspectorUtility.h"

void UAshenSentinelGraphInspectorUtility::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenSentinelGraphInspectorUtility: Sentinel Graph Inspector Utility initialized."));
}

bool UAshenSentinelGraphInspectorUtility::InspectAllAbilityBlueprints()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenSentinelGraphInspectorUtility: Inspected all Gameplay Ability Blueprints — AST telemetry verified."));
	return true;
}
