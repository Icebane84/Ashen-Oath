// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenMemoryBleedVisualController.generated.h"

/**
 * UAshenMemoryBleedVisualController
 * UI / Post-Process controller driving edge desaturation, memory bleed vignette shimmer, and HUD text jitter during Memory Bleed and Runtime Noise stages.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryBleedVisualController : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryBleedVisualController();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float EdgeDesaturationIntensity = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float HUDJitterFrequency = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void ApplyMemoryBleedVisualEffects(EAshenIntegrationDebtStage Stage);
};
