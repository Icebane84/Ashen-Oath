// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettFlankInterceptionEvaluatorComponent.h"

UAshenGarrettFlankInterceptionEvaluatorComponent::UAshenGarrettFlankInterceptionEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FVector UAshenGarrettFlankInterceptionEvaluatorComponent::EvaluateInterceptionPosition(const FVector& KaelenLocation, const FVector& FlankingEnemyLocation, float GarrettTrust)
{
	FVector InterceptionVector = FMath::Lerp(FlankingEnemyLocation, KaelenLocation, 0.5f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettFlankInterceptionEvaluatorComponent: Evaluated flank interception position for Garrett (Trust: %.2f)"), GarrettTrust);
	return InterceptionVector;
}
