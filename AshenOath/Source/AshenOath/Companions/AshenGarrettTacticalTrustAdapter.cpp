// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenGarrettTacticalTrustAdapter.h"

UAshenGarrettTacticalTrustAdapter::UAshenGarrettTacticalTrustAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGarrettTacticalTrustAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenGarrettTacticalTrustAdapter::UpdateTacticalTrustScaling(float GarrettTrustScore)
{
	InterposeRescueChance = FMath::Clamp(GarrettTrustScore, 0.1f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettTacticalTrustAdapter: Interpose rescue chance updated to %.2f (Trust: %.2f)"),
		InterposeRescueChance, GarrettTrustScore);
}
