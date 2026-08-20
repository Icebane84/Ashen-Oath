// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ArmorScuffDebugHUD.generated.h"

/**
 * UAshenUserWidget_ArmorScuffDebugHUD
 *
 * UMG backing widget rendering visual telemetry for armor scuff intensity and material Parameter blend.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ArmorScuffDebugHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateArmorScuffHUDDisplay(float SeverityPercent);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedSeverityPercent = 0.0f;
};
