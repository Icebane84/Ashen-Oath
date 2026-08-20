// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenShadowSeepageDialogueAdapter.h"

UAshenShadowSeepageDialogueAdapter::UAshenShadowSeepageDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenShadowSeepageDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenShadowSeepageDialogueAdapter::TriggerSeepageReactionBark(FName CompanionID, EShadowSeepagePhase Phase)
{
	FString Bark = TEXT("Stay focused.");
	if (Phase == EShadowSeepagePhase::CrimsonSurge)
	{
		Bark = TEXT("Kaelen, your arm—the red static is taking your eyes! Hold on to us!");
	}
	else if (Phase == EShadowSeepagePhase::BileSeepage)
	{
		Bark = TEXT("The shadow stain is weeping through the armor seams... we need to find an altar soon.");
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenShadowSeepageDialogueAdapter: %s: \"%s\" (Phase: %d)"),
		*CompanionID.ToString(), *Bark, static_cast<int32>(Phase));
}
