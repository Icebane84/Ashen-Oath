// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_TrustLevelMeter.generated.h"

/**
 * UAshenUserWidget_TrustLevelMeter
 *
 * UMG backing widget rendering the HUD companion trust meter & synergy damage multiplier bonus.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TrustLevelMeter : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateTrustDisplay(FName CompanionName, float TrustScore, float SynergyMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveCompanionName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActiveTrustScore = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActiveSynergyMultiplier = 1.0f;
};
