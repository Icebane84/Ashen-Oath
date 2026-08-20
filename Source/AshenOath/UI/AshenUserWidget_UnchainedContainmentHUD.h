// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AI/AshenShepherdsGambitTypes.h"
#include "AshenUserWidget_UnchainedContainmentHUD.generated.h"

/**
 * UAshenUserWidget_UnchainedContainmentHUD
 * Somatic HUD displaying companion containment status, golden tether stability, and Kaelen's remaining humanity reserve.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_UnchainedContainmentHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EContainmentState ContainmentState = EContainmentState::StandardCooperation;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateContainmentState(EContainmentState NewState);
};
