// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameplayTagContainer.h"
#include "AshenEntropyDecayEvaluator.generated.h"

/**
 * UAshenEntropyDecayEvaluator
 * Evaluator executing LAW-041 Entropy Decay equations R(S'_j) = R_base * (1 - gamma * N_recent) to prevent AI pattern looping.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEntropyDecayEvaluator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEntropyDecayEvaluator();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Entropy")
	float EntropyGamma = 0.4f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Entropy")
	float EntropyWindowSeconds = 15.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Entropy")
	float CalculateDecayedUtility(float BaseUtility, int32 RecentUsageCount);
};
