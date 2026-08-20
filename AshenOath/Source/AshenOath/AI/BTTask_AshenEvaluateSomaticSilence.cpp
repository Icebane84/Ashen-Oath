// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "AI/BTTask_AshenEvaluateSomaticSilence.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Companions/AshenSomaticSilenceTypes.h"

UBTTask_AshenEvaluateSomaticSilence::UBTTask_AshenEvaluateSomaticSilence()
{
	NodeName = TEXT("Ashen Evaluate Somatic Silence");
	SilenceStateBlackboardKey = FName(TEXT("SilenceState"));
	TargetSpacingBlackboardKey = FName(TEXT("TargetSpacingUU"));
}

EBTNodeResult::Type UBTTask_AshenEvaluateSomaticSilence::ExecuteTask(
	UBehaviorTreeComponent& OwnerComp,
	uint8* NodeMemory)
{
	AAIController* AICon = OwnerComp.GetAIOwner();
	if (!AICon)
	{
		return EBTNodeResult::Failed;
	}

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		Blackboard->SetValueAsEnum(SilenceStateBlackboardKey, static_cast<uint8>(ESomaticSilenceClassification::Contemplative));
		Blackboard->SetValueAsFloat(TargetSpacingBlackboardKey, 500.0f);
	}

	return EBTNodeResult::Succeeded;
}
