// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenRegionalCorruptionAtmosphereAdapter.generated.h"

/**
 * UAshenRegionalCorruptionAtmosphereAdapter
 * Modulates sky fog color, thunderstorm frequency, and environmental ash rain based on active sector corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRegionalCorruptionAtmosphereAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenRegionalCorruptionAtmosphereAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Environment")
	void UpdateSectorAtmosphere(int32 SectorIndex, float CorruptionLevel);
};
