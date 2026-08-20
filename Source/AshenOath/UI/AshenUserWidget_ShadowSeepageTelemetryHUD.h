// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenUserWidget_ShadowSeepageTelemetryHUD.generated.h"

/**
 * UAshenUserWidget_ShadowSeepageTelemetryHUD
 * Somatic UI HUD displaying active seepage phase, emitter spawn rates, and skeletal joint offset tracking.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ShadowSeepageTelemetryHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EShadowSeepagePhase DisplayedPhase = EShadowSeepagePhase::Dormant;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedNormalOffset = 0.1f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float DisplayedSparksSpawnRate = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateTelemetryHUD(EShadowSeepagePhase InPhase, float InNormalOffset, float InSparksRate);
};
