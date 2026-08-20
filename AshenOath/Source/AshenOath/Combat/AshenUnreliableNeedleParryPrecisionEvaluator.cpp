// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenUnreliableNeedleParryPrecisionEvaluator.h"

UAshenUnreliableNeedleParryPrecisionEvaluator::UAshenUnreliableNeedleParryPrecisionEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenUnreliableNeedleParryPrecisionEvaluator::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ParryWindowMarginSeconds = FMath::Clamp(0.25f - (NewState.Isolation * 0.12f), 0.10f, 0.30f);
	UE_LOG(LogTemp, Log, TEXT("UAshenUnreliableNeedleParryPrecisionEvaluator: Parry window margin set to %.3f seconds"), ParryWindowMarginSeconds);
}
