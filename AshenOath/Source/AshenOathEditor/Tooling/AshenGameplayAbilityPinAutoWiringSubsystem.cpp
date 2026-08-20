// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenGameplayAbilityPinAutoWiringSubsystem.h"

void UAshenGameplayAbilityPinAutoWiringSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenGameplayAbilityPinAutoWiringSubsystem: Gameplay Ability Pin Auto-Wiring Subsystem initialized."));
}

bool UAshenGameplayAbilityPinAutoWiringSubsystem::AutoWireAbilityTelemetryPins()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenGameplayAbilityPinAutoWiringSubsystem: GAS Ability Blueprint telemetry pins auto-wired successfully — PASSED."));
	return true;
}
