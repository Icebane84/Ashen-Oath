// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 538: Ashen Ascension Chamber Volume

#include "AshenAscensionChamberVolume.h"

AAshenAscensionChamberVolume::AAshenAscensionChamberVolume()
{
	PrimaryActorTick.bCanEverTick = false;
	bAscensionActive = false;
}

void AAshenAscensionChamberVolume::TriggerAscensionRitual(AActor* InitiatorActor, FName AscensionTierTag)
{
	if (!InitiatorActor || AscensionTierTag.IsNone()) return;

	bAscensionActive = true;
	OnAscensionActivated.Broadcast(InitiatorActor, AscensionTierTag);

	UE_LOG(LogTemp, Warning, TEXT("AAshenAscensionChamberVolume: ASCENSION RITUAL TRIGGERED by '%s' -> Tier '%s'."),
		*InitiatorActor->GetName(), *AscensionTierTag.ToString());
}
