// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaCoopComboStateTreeEvaluator.h"

UAshenSerafinaCoopComboStateTreeEvaluator::UAshenSerafinaCoopComboStateTreeEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}

bool UAshenSerafinaCoopComboStateTreeEvaluator::EvaluateComboOpportunity(float SerafinaTrust, float StaggeredEnemyDistance) const
{
	bool bOpportunityAvailable = (SerafinaTrust >= 0.5f) && (StaggeredEnemyDistance <= 600.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaCoopComboStateTreeEvaluator: Combo opportunity evaluated to %s"), bOpportunityAvailable ? TEXT("TRUE") : TEXT("FALSE"));
	return bOpportunityAvailable;
}
