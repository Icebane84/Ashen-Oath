// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTraumaSaveGameAdapter.generated.h"

/**
 * UAshenTraumaSaveGameAdapter
 * Serializes peak integration debt reached, total unchained vessel activations, and forced mindscape entries to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTraumaSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveTraumaMetrics(float PeakDebt, int32 UnchainedActivationsCount, int32 ForcedMindscapeCount);
};
