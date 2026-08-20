// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenLensCompanionTrustAdapter.h"

UAshenLensCompanionTrustAdapter::UAshenLensCompanionTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenLensCompanionTrustAdapter::BeginPlay() { Super::BeginPlay(); }

float UAshenLensCompanionTrustAdapter::ModulateTrustDelta(FName CompanionID, float BaseDelta, EInterpretiveLens Lens)
{
	float FinalDelta = BaseDelta;
	if (CompanionID == FName(TEXT("Garrett")) && Lens == EInterpretiveLens::Accountability)
	{
		FinalDelta *= 1.15f; // +15% trust rate
	}
	else if (CompanionID == FName(TEXT("Serafina")) && Lens == EInterpretiveLens::Grace)
	{
		FinalDelta *= 1.15f; // +15% trust rate
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenLensCompanionTrustAdapter: Modulated trust delta for %s from %.3f to %.3f (Lens: %d)."),
		*CompanionID.ToString(), BaseDelta, FinalDelta, static_cast<int32>(Lens));
	return FinalDelta;
}
