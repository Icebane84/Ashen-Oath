// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenShadowSeepageSaveGameAdapter.generated.h"

/**
 * UAshenShadowSeepageSaveGameAdapter
 * Serializes peak corruption seepage records, unchained vessel duration, and bile puddle generation metrics to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShadowSeepageSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShadowSeepageSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveSeepageStatistics(float PeakCorruptionReached, float TotalUnchainedTime);
};
