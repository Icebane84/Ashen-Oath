// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 371: Ashen Focus Mode Investigation Component

#include "AshenFocusModeInvestigationComponent.h"

UAshenFocusModeInvestigationComponent::UAshenFocusModeInvestigationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bFocusModeActive = false;
}

void UAshenFocusModeInvestigationComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenFocusModeInvestigationComponent::ToggleFocusMode(bool bEnable)
{
	bFocusModeActive = bEnable;
	const float Range = bEnable ? 1200.0f : 0.0f;

	OnFocusModeStateChanged.Broadcast(bEnable, Range);

	UE_LOG(LogTemp, Warning, TEXT("UAshenFocusModeInvestigationComponent: FOCUS MODE TOGGLED -> Active: %s (Investigation Range: %.0fu)."),
		bEnable ? TEXT("TRUE") : TEXT("FALSE"), Range);
}
