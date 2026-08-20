// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SwordPostureHUD.generated.h"

/**
 * UAshenUserWidget_SwordPostureHUD
 *
 * UMG backing widget rendering visual telemetry for sword posture alignment & parry sweet-spot timing.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SwordPostureHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateSwordPostureHUDDisplay(FName StanceTag, float ParryMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedStanceTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedParryMultiplier = 1.0f;
};
