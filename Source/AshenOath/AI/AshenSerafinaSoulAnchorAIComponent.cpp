// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenSerafinaSoulAnchorAIComponent.h"

UAshenSerafinaSoulAnchorAIComponent::UAshenSerafinaSoulAnchorAIComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentContainmentAction = EContainmentState::StandardCooperation;
}
void UAshenSerafinaSoulAnchorAIComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenSerafinaSoulAnchorAIComponent::EvaluateSerafinaContainmentTree(bool bIsKaelenUnchained, bool bIsKaelenTargetingAllies, float EmpathicBurnout)
{
	if (!bIsKaelenUnchained)
	{
		CurrentContainmentAction = EContainmentState::StandardCooperation;
		return;
	}

	if (EmpathicBurnout >= 0.70f)
	{
		CurrentContainmentAction = EContainmentState::BulwarkLockout;
		UE_LOG(LogTemp, Error, TEXT("UAshenSerafinaSoulAnchorAIComponent: BULWARK LOCKOUT (Burnout: %.2f)! Aura of Sanctity only!"), EmpathicBurnout);
		return;
	}

	if (bIsKaelenTargetingAllies)
	{
		CurrentContainmentAction = EContainmentState::ContainmentActive;
		UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaSoulAnchorAIComponent: Kaelen targeting allies -> CASTING SUN-PULSE DISORIENT!"));
	}
	else
	{
		CurrentContainmentAction = EContainmentState::ContainmentActive;
		UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaSoulAnchorAIComponent: Kaelen wild -> CHANNELING SANCTUARY ANCHOR DAMPENER!"));
	}
}
