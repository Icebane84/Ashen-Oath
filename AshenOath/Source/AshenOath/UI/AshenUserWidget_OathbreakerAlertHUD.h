// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenUserWidget_OathbreakerAlertHUD.generated.h"

/**
 * UAshenUserWidget_OathbreakerAlertHUD
 * Diegetic HUD warning indicating active oath fracture, corruption penalty values, and sword rebellion status.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_OathbreakerAlertHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsAlertActive = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EAshenLivingOathType FracturedOath = EAshenLivingOathType::None;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void TriggerOathbreakerAlert(EAshenLivingOathType BrokenOath);
};
