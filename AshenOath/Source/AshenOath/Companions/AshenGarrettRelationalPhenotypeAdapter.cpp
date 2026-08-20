// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettRelationalPhenotypeAdapter.h"

UAshenGarrettRelationalPhenotypeAdapter::UAshenGarrettRelationalPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettRelationalPhenotypeAdapter::UpdateGarrettBehavior(float GarrettTrust, float Isolation)
{
	FormationDistanceScalar = FMath::Clamp(1.0f + (Isolation * 1.5f) - (GarrettTrust * 0.5f), 0.5f, 3.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettRelationalPhenotypeAdapter: Garrett formation distance scalar updated to %.2f"), FormationDistanceScalar);
}
