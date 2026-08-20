// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenControllerFrictionSaveGameAdapter.generated.h"

/**
 * UAshenControllerFrictionSaveGameAdapter
 * Serializes struggle telemetry, successful trigger lock holds, and protective intercepts to SaveGame.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenControllerFrictionSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenControllerFrictionSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveFrictionTelemetry(int32 SuccessfulLockHolds, int32 InterceptCount, int32 ReclamationCount);
};
