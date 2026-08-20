// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenSerafinaTrustBurnoutAdapter.h"

UAshenSerafinaTrustBurnoutAdapter::UAshenSerafinaTrustBurnoutAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenSerafinaTrustBurnoutAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenSerafinaTrustBurnoutAdapter::UpdateBurnoutDissipationForTrust(float SerafinaTrustScore)
{
	AdjustedDissipationRate = 1.0f + (SerafinaTrustScore * 2.5f); // 1.0 to 3.5 dissipation rate
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaTrustBurnoutAdapter: Burnout dissipation rate set to %.2f/s (Trust: %.2f)"),
		AdjustedDissipationRate, SerafinaTrustScore);
}
