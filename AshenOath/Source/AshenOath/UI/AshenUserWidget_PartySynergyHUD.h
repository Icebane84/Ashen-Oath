// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_PartySynergyHUD.generated.h"

/**
 * UAshenUserWidget_PartySynergyHUD
 *
 * UMG backing widget displaying active companion synergy buffs and proximity meters.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PartySynergyHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdatePartySynergyHUDDisplay(float SynergyMultiplier, int32 CompanionsInProximity);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedSynergyMultiplier = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	int32 DisplayedCompanionCount = 0;
};
