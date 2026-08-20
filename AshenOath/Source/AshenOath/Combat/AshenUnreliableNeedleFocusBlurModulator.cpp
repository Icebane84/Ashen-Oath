// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliableNeedleFocusBlurModulator.h"

UAshenUnreliableNeedleFocusBlurModulator::UAshenUnreliableNeedleFocusBlurModulator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliableNeedleFocusBlurModulator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	FocusBlurFocalDistance = FMath::Clamp(1000.0f - (NewState.Isolation * 600.0f), 400.0f, 1000.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNeedleFocusBlurModulator: Focus blur focal distance set to %.1f units"), FocusBlurFocalDistance);
}
