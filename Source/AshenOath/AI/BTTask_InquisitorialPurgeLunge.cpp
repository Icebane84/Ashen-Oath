// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/BTTask_InquisitorialPurgeLunge.h"

UBTTask_InquisitorialPurgeLunge::UBTTask_InquisitorialPurgeLunge()
{
	NodeName = TEXT("Inquisitorial Purge Lunge");
}

EBTNodeResult::Type UBTTask_InquisitorialPurgeLunge::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Log, TEXT("UBTTask_InquisitorialPurgeLunge: Executed purge lunge at %.0f speed."), LungeSpeed);
	return EBTNodeResult::Succeeded;
}
