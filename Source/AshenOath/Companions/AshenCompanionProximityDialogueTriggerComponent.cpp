// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenCompanionProximityDialogueTriggerComponent.h"

UAshenCompanionProximityDialogueTriggerComponent::UAshenCompanionProximityDialogueTriggerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionProximityDialogueTriggerComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	ProximityBarkCooldown = FMath::Clamp(15.0f - (NewState.Isolation * 10.0f), 5.0f, 30.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionProximityDialogueTriggerComponent: Proximity bark cooldown updated to %.1f seconds"), ProximityBarkCooldown);
}
