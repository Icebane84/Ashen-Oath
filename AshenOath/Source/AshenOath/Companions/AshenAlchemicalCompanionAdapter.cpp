// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenAlchemicalCompanionAdapter.h"

UAshenAlchemicalCompanionAdapter::UAshenAlchemicalCompanionAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenAlchemicalCompanionAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenAlchemicalCompanionAdapter::ShouldGarrettDeployAssistTrap(float GarrettTrust, bool bIsPlayerFlanked) const
{
	// Assist triggered if player is flanked and trust >= 0.50
	const bool bShouldAssist = bIsPlayerFlanked && (GarrettTrust >= 0.50f);
	if (bShouldAssist)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenAlchemicalCompanionAdapter: Garrett deploying assist trap to cover Kaelen's flank!"));
	}
	return bShouldAssist;
}
