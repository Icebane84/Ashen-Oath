// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaEmpathicPhenotypeAdapter.h"

UAshenSerafinaEmpathicPhenotypeAdapter::UAshenSerafinaEmpathicPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaEmpathicPhenotypeAdapter::UpdateSerafinaBehavior(float SerafinaTrust, float Resolve)
{
	SupportFrequencyMultiplier = FMath::Clamp((SerafinaTrust * 1.5f) + ((1.0f - Resolve) * 0.5f), 0.2f, 2.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaEmpathicPhenotypeAdapter: Serafina support frequency multiplier updated to %.2f"), SupportFrequencyMultiplier);
}
