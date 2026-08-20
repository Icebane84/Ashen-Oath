// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_TacticalTargetingHUD.generated.h"

/**
 * UAshenUserWidget_TacticalTargetingHUD
 *
 * UMG backing widget rendering weak point lock indicators during TSC slow-mo.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TacticalTargetingHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateTargetingDisplay(FName BoneName, float CritMultiplier);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedBoneName;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedCritMultiplier = 1.0f;
};
