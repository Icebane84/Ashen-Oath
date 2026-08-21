// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenEmitCompanionHapticCue.h"
#include "AIController.h"

UBTTask_AshenEmitCompanionHapticCue::UBTTask_AshenEmitCompanionHapticCue()
{
	NodeName = TEXT("Ashen Emit Companion Haptic Cue");
	Channel = ETactileWhisperChannel::GarrettTactical;
}

EBTNodeResult::Type UBTTask_AshenEmitCompanionHapticCue::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon)
	{
		return EBTNodeResult::Failed;
	}

	return EBTNodeResult::Succeeded;
}
