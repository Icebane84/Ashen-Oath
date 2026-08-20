// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 718: Ashen Serafina Lorekeeper Insight Evaluator

#include "AshenSerafinaLorekeeperInsightEvaluator.h"

UAshenSerafinaLorekeeperInsightEvaluator::UAshenSerafinaLorekeeperInsightEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalNodesAnalyzed = 0;
}

void UAshenSerafinaLorekeeperInsightEvaluator::EvaluateLorekeeperInsight(FName LoreNodeTag)
{
	TotalNodesAnalyzed++;
	const float Bonus = 15.0f * TotalNodesAnalyzed;

	OnInsightEvaluated.Broadcast(LoreNodeTag, Bonus);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaLorekeeperInsightEvaluator: LOREKEEPER INSIGHT EVALUATED -> Node: '%s' | Insight Bonus: +%.0f%% (Total Nodes: %d)."),
		*LoreNodeTag.ToString(), Bonus, TotalNodesAnalyzed);
}
