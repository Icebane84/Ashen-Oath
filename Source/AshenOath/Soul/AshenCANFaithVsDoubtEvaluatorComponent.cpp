// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 641: Ashen CAN Faith Vs Doubt Evaluator Component

#include "AshenCANFaithVsDoubtEvaluatorComponent.h"

UAshenCANFaithVsDoubtEvaluatorComponent::UAshenCANFaithVsDoubtEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	ActiveFaithLevel = 0.5f;
	ActiveDoubtLevel = 0.5f;
}

void UAshenCANFaithVsDoubtEvaluatorComponent::EvaluateFaithVsDoubt(float DeltaFaith, float DeltaDoubt)
{
	ActiveFaithLevel = FMath::Clamp(ActiveFaithLevel + DeltaFaith, 0.0f, 1.0f);
	ActiveDoubtLevel = FMath::Clamp(ActiveDoubtLevel + DeltaDoubt, 0.0f, 1.0f);

	OnFaithVsDoubtEvaluated.Broadcast(ActiveFaithLevel, ActiveDoubtLevel);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCANFaithVsDoubtEvaluatorComponent: FAITH VS DOUBT EVALUATED -> Faith: %.2f | Doubt: %.2f (can-faith_vs_doubt)."),
		ActiveFaithLevel, ActiveDoubtLevel);
}
