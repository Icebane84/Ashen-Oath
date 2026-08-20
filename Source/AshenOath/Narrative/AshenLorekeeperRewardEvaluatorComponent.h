// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenLorekeeperRewardEvaluatorComponent.generated.h"

/**
 * UAshenLorekeeperRewardEvaluatorComponent
 * Computes cumulative faction codex stat rewards: Sanity maximum, Poise baseline, and psychic resolve regeneration.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLorekeeperRewardEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLorekeeperRewardEvaluatorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	float CalculatePoiseReward(int32 UnlockedOathswornCount) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Codex")
	float CalculateResolveRegenBonus(int32 TotalReadEntries) const;
};
