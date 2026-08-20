// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CompanionSynergyMeter.generated.h"

/**
 * UAshenUserWidget_CompanionSynergyMeter
 *
 * UMG backing widget for rendering the HUD companion combo synergy meter and active multiplier.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CompanionSynergyMeter : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateSynergyDisplay(float SynergyPercent, float Multiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CachedSynergyPercent = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CachedMultiplier = 1.0f;
};
