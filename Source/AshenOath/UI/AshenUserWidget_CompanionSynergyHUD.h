// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CompanionSynergyHUD.generated.h"

/**
 * UAshenUserWidget_CompanionSynergyHUD
 * UMG widget displaying real-time Garrett/Serafina trust meters, fatigue burn bars, and ResonanceSync activation status.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CompanionSynergyHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float GarrettTrustPercent = 0.5f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float SerafinaTrustPercent = 0.5f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bResonanceSyncActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshSynergyHUD(float GarrettTrust, float SerafinaTrust, bool bSyncActive);
};
