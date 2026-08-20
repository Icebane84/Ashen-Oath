// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenCompanionPathfindingNoiseAdapter.generated.h"

/**
 * UAshenCompanionPathfindingNoiseAdapter
 * Companion adapter injecting 200ms simulated pathfinding decision delays into Garrett and Serafina during Runtime Noise.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionPathfindingNoiseAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionPathfindingNoiseAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	float PathfindingDecisionDelaySeconds = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	void EvaluatePathfindingNoise(EAshenIntegrationDebtStage Stage);
};
