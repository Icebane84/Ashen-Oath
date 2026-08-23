// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Scenarios/AshenBleedingWaystationTypes.h"
#include "AshenUserWidget_WaystationCrucibleHUD.generated.h"

/**
 * UAshenUserWidget_WaystationCrucibleHUD
 * 
 * UMG widget visualizing formation spacing distances, StateTree hesitation latency, and IntegrationDebt.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_WaystationCrucibleHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_WaystationCrucibleHUD(const FObjectInitializer& ObjectInitializer);

	/** Updates the waystation crucible telemetry indicators */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Waystation")
	void UpdateCrucibleHUD(
		EWaystationRunMode Mode,
		float SerafinaDistance,
		float HesitationLatencyMS,
		float IntegrationDebt);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Waystation")
	EWaystationRunMode DisplayedRunMode = EWaystationRunMode::RunA_ShadowHarvest;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Waystation")
	float DisplayedSerafinaDistance = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Waystation")
	float DisplayedHesitationMS = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Waystation")
	float DisplayedDebt = 0.20f;
};
