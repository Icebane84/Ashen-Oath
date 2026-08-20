// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 763: Ashen Campfire Dialogue Trigger Zone Actor

#include "AshenCampfireDialogueTriggerZoneActor.h"

AAshenCampfireDialogueTriggerZoneActor::AAshenCampfireDialogueTriggerZoneActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bHasTriggered = false;
}

void AAshenCampfireDialogueTriggerZoneActor::TriggerCampfireDialogue(FName SequenceID)
{
	bHasTriggered = true;
	OnDialogueTriggered.Broadcast(SequenceID, 3); // Kaelen, Serafina, Garrett

	UE_LOG(LogTemp, Warning, TEXT("AAshenCampfireDialogueTriggerZoneActor: CAMPFIRE DIALOGUE TRIGGERED -> Sequence: '%s' | Party Members: 3."),
		*SequenceID.ToString());
}
