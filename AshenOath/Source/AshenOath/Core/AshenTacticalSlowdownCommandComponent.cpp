// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 323: Ashen Tactical Slowdown Command Component

#include "AshenTacticalSlowdownCommandComponent.h"
#include "Kismet/GameplayStatics.h"

UAshenTacticalSlowdownCommandComponent::UAshenTacticalSlowdownCommandComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SlowdownDilationScale = 0.20f;
	bSlowdownActive = false;
}

void UAshenTacticalSlowdownCommandComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenTacticalSlowdownCommandComponent::ActivateTacticalSlowdown()
{
	bSlowdownActive = true;

	if (GetWorld())
	{
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), SlowdownDilationScale);
	}

	OnSlowdownStateChanged.Broadcast(true, SlowdownDilationScale);

	UE_LOG(LogTemp, Warning, TEXT("UAshenTacticalSlowdownCommandComponent: TACTICAL SLOWDOWN (TSC) ACTIVATED — Time Dilation set to %.2fx."),
		SlowdownDilationScale);

	return true;
}

void UAshenTacticalSlowdownCommandComponent::DeactivateTacticalSlowdown()
{
	bSlowdownActive = false;

	if (GetWorld())
	{
		UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.0f);
	}

	OnSlowdownStateChanged.Broadcast(false, 1.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenTacticalSlowdownCommandComponent: Tactical slowdown deactivated. Normal time restored."));
}
