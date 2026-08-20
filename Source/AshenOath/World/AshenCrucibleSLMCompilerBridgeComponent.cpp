// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenCrucibleSLMCompilerBridgeComponent.h"

UAshenCrucibleSLMCompilerBridgeComponent::UAshenCrucibleSLMCompilerBridgeComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCrucibleSLMCompilerBridgeComponent::TriggerCrucibleCompilation()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenCrucibleSLMCompilerBridgeComponent: Triggering async SLM Identity Compilation bridge at Heartstone Shrine."));
}
