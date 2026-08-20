// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettAIFormationPhenotypeAdapter.h"

UAshenGarrettAIFormationPhenotypeAdapter::UAshenGarrettAIFormationPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGarrettAIFormationPhenotypeAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	FormationDistance = 300.0f * (1.0f + (NewState.Isolation * 1.5f) - (NewState.GarrettTrust * 0.5f));
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettAIFormationPhenotypeAdapter: Garrett AI formation distance updated to %.1f units"), FormationDistance);
}
