// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionCombatBanterQueueComponent.h"

UAshenCompanionCombatBanterQueueComponent::UAshenCompanionCombatBanterQueueComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionCombatBanterQueueComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	AlignmentBalance = (NewState.GarrettTrust + NewState.SerafinaTrust) * 0.5f;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionCombatBanterQueueComponent: Alignment balance set to %.2f"), AlignmentBalance);
}

FString UAshenCompanionCombatBanterQueueComponent::PopNextBanterLine()
{
	if (AlignmentBalance > 0.7f)
	{
		return TEXT("Garrett: 'Together! Cut them down!'");
	}
	return TEXT("Garrett: 'Watch your flank, Kaelen!'");
}
