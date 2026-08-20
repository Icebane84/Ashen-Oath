// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaLorekeeperInsightEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLorekeeperInsightEvaluatedSignature, FName, DiscoveredLoreNode, float, InsightBonusPercent);

/**
 * UAshenSerafinaLorekeeperInsightEvaluator
 *
 * Subsystem evaluating Serafina's can-conspiracy_of_silence and lore node discovery (PRS-001 Serafina Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaLorekeeperInsightEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaLorekeeperInsightEvaluator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaLore")
	void EvaluateLorekeeperInsight(FName LoreNodeTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaLore|Events")
	FOnLorekeeperInsightEvaluatedSignature OnInsightEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SerafinaLore")
	int32 TotalNodesAnalyzed = 0;
};
