// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenUserWidget_CostlyPresencePromptHUD.generated.h"

/**
 * UAshenUserWidget_CostlyPresencePromptHUD
 * 
 * Subtle diegetic UMG HUD element rendering:
 * - Vignette flare when Garrett/Serafina initiates Costly Presence
 * - Intercept trajectory indicator
 * - Dynamic companion icon pulse
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CostlyPresencePromptHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_CostlyPresencePromptHUD(const FObjectInitializer& ObjectInitializer);

	/** Triggers the costly presence intercept notification */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Ecology")
	void TriggerInterceptNotification(FName CompanionName, ECompanionInterventionType Type);

	/** Dismisses prompt */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Ecology")
	void DismissNotification();

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Ecology")
	bool IsNotificationActive() const { return bActive; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Ecology")
	FName ActiveCompanionName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Ecology")
	float NotificationOpacity = 0.0f;

private:
	bool bActive = false;
};
