// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_BossPhaseHUD.generated.h"

/**
 * UAshenUserWidget_BossPhaseHUD
 *
 * UMG backing widget rendering visual telemetry for boss health phase thresholds and enrage status.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BossPhaseHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateBossPhaseHUDDisplay(int32 PhaseIndex, float HealthPercent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedPhaseIndex = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedHealthPercent = 1.0f;
};
