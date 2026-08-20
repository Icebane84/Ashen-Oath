// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_BrotherMalakorBossBar.generated.h"

/**
 * UAshenUserWidget_BrotherMalakorBossBar
 * 3-segmented gilded inquisitorial boss healthbar with phase transition indicators.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_BrotherMalakorBossBar : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float BossHealthRatio = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActivePhaseIndex = 1;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateBossHealthHUD(float HealthPercent, int32 PhaseIndex);
};
