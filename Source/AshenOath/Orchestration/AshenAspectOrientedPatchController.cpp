// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 654: Ashen Aspect Oriented Patch Controller (AOP)

#include "AshenAspectOrientedPatchController.h"

void UAshenAspectOrientedPatchController::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	TotalActivePatchesCount = 0;
	UE_LOG(LogTemp, Log, TEXT("UAshenAspectOrientedPatchController: Initialized — Aspect-Oriented Patch Controller (AOP) ONLINE."));
}

void UAshenAspectOrientedPatchController::ApplyAspectOrientedPatch(FName PatchID, FName TargetSubsystem)
{
	if (PatchID.IsNone()) return;

	TotalActivePatchesCount++;
	OnPatchApplied.Broadcast(PatchID, TargetSubsystem, true);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAspectOrientedPatchController: AOP PATCH APPLIED -> Patch '%s' ==> Target '%s' (Total Active Patches: %d)."),
		*PatchID.ToString(), *TargetSubsystem.ToString(), TotalActivePatchesCount);
}
