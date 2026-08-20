// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 194: Ashen Player Stance FX Component

#include "AshenPlayerStanceFXComponent.h"

UAshenPlayerStanceFXComponent::UAshenPlayerStanceFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveStance = EStanceProfile::Balanced_Steady;
}

void UAshenPlayerStanceFXComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenPlayerStanceFXComponent::TriggerStanceFX(EStanceProfile StanceProfile, float Intensity)
{
	ActiveStance = StanceProfile;
	OnStanceFXTriggered.Broadcast(ActiveStance, Intensity);

	const TCHAR* StanceStr = TEXT("Balanced / Steady");
	if (StanceProfile == EStanceProfile::Hunched_Guarded) StanceStr = TEXT("Hunched / Guarded");
	else if (StanceProfile == EStanceProfile::Upright_Grounded) StanceStr = TEXT("Upright / Grounded");

	UE_LOG(LogTemp, Warning, TEXT("UAshenPlayerStanceFXComponent: Stance FX TRIGGERED for stance '%s' (Intensity: %.1f)."),
		StanceStr, Intensity);
}
