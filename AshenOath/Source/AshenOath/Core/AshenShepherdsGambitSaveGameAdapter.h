// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenShepherdsGambitSaveGameAdapter.generated.h"

/**
 * UAshenShepherdsGambitSaveGameAdapter
 * Serializes unchained event counts, successful companion containment resolutions, and party burnout logs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShepherdsGambitSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShepherdsGambitSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveContainmentTelemetry(int32 UnchainedCrisisCount, int32 SunPulsesFired, int32 NeedlesDeployed);
};
