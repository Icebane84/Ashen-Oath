// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaAuraPhenotypeAdapter.h"

UAshenSerafinaAuraPhenotypeAdapter::UAshenSerafinaAuraPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSerafinaAuraPhenotypeAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ShieldFrequency = FMath::Clamp((NewState.SerafinaTrust * 1.5f) + ((1.0f - NewState.Resolve) * 0.5f), 0.2f, 2.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaAuraPhenotypeAdapter: Serafina protective aura frequency updated to %.2f"), ShieldFrequency);
}
