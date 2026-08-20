// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_FullPsychologicalLoopHUD.generated.h"

/**
 * UAshenUserWidget_FullPsychologicalLoopHUD
 *
 * UMG backing widget rendering real-time telemetry across all 7 stages of the Psychological Loop.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_FullPsychologicalLoopHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateLoopTelemetry(int32 StageMask, float SoulDebt, float TrustScore, float CorruptionLevel);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 ActiveStageMask = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float TelemetrySoulDebt = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float TelemetryTrustScore = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float TelemetryCorruptionLevel = 0.0f;
};
