// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenBossIncursionSaveGameAdapter.generated.h"

/**
 * UAshenBossIncursionSaveGameAdapter
 * Serializes boss clear times, defeat states, and total Tripartite Finishers executed.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossIncursionSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossIncursionSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveBossClearRecord(FName BossId, float ClearTimeSeconds, int32 TotalStaggers);
};
