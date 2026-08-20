// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 468: Ashen Companion Emotional Residue Component

#include "AshenCompanionEmotionalResidueComponent.h"

UAshenCompanionEmotionalResidueComponent::UAshenCompanionEmotionalResidueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CalculatedTotalResidue = 0.0f;
}

void UAshenCompanionEmotionalResidueComponent::AccumulateEmotionalResidue(FName CompanionID, float DeltaResidue)
{
	CalculatedTotalResidue = FMath::Clamp(CalculatedTotalResidue + DeltaResidue, 0.0f, 100.0f);
	OnResidueAccumulated.Broadcast(CompanionID, CalculatedTotalResidue);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCompanionEmotionalResidueComponent: EMOTIONAL RESIDUE ACCUMULATED -> Companion '%s' (+%.1f) Total: %.1f."),
		*CompanionID.ToString(), DeltaResidue, CalculatedTotalResidue);
}
