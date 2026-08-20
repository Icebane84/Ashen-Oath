// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCampfireDialogueTriggerZoneActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCampfireDialogueTriggeredSignature, FName, DialogueSequenceID, int32, PartyMembersPresentCount);

/**
 * AAshenCampfireDialogueTriggerZoneActor
 *
 * Trigger zone initiating Act 01 party camp dialogues between Kaelen, Serafina, and Garrett (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API AAshenCampfireDialogueTriggerZoneActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenCampfireDialogueTriggerZoneActor();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|CampfireDialogue")
	void TriggerCampfireDialogue(FName SequenceID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|CampfireDialogue|Events")
	FOnCampfireDialogueTriggeredSignature OnDialogueTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|CampfireDialogue")
	bool bHasTriggered = false;
};
