// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/BTTask_ShroudWarpStrike.h"

UBTTask_ShroudWarpStrike::UBTTask_ShroudWarpStrike()
{
	NodeName = TEXT("Shroud Warp Strike");
}

EBTNodeResult::Type UBTTask_ShroudWarpStrike::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UE_LOG(LogTemp, Log, TEXT("UBTTask_ShroudWarpStrike: Executed spectral warp strike (%.0fuu behind target)."), WarpDistanceBehind);
	return EBTNodeResult::Succeeded;
}
