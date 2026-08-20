// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenActiveMemoryWeavingSaveGameAdapter.generated.h"

/**
 * UAshenActiveMemoryWeavingSaveGameAdapter
 * Serializes memory weaving telemetry: total light bridges manifested, aegis nets deployed, and filament snaps.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenActiveMemoryWeavingSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenActiveMemoryWeavingSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveWeavingTelemetry(int32 BridgesManifested, int32 NetsDeployed, int32 SnappedThreads);
};
