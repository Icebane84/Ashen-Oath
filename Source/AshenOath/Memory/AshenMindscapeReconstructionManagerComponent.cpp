// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Memory/AshenMindscapeReconstructionManagerComponent.h"

UAshenMindscapeReconstructionManagerComponent::UAshenMindscapeReconstructionManagerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ResolveDrainRatePerSecond = 15.0f;
	CurrentReconstructionProgress = 0.0f;
}
void UAshenMindscapeReconstructionManagerComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenMindscapeReconstructionManagerComponent::AdvanceReconstruction(float DeltaSeconds, float AvailableResolve, float& OutRemainingResolve)
{
	const float RequiredResolve = ResolveDrainRatePerSecond * DeltaSeconds;
	if (AvailableResolve < RequiredResolve)
	{
		OutRemainingResolve = AvailableResolve;
		UE_LOG(LogTemp, Warning, TEXT("UAshenMindscapeReconstructionManagerComponent: Insufficient Resolve to continue psychic reconstruction."));
		return false;
	}

	OutRemainingResolve = AvailableResolve - RequiredResolve;
	CurrentReconstructionProgress = FMath::Clamp(CurrentReconstructionProgress + (0.25f * DeltaSeconds), 0.0f, 1.0f);

	UE_LOG(LogTemp, Log, TEXT("UAshenMindscapeReconstructionManagerComponent: Reconstruction Progress: %.1f%% (Remaining Resolve: %.1f)."),
		CurrentReconstructionProgress * 100.0f, OutRemainingResolve);

	return CurrentReconstructionProgress >= 1.0f;
}
