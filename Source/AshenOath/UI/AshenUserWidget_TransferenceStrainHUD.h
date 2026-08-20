// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenPsychicStrainTypes.h"
#include "AshenUserWidget_TransferenceStrainHUD.generated.h"

/**
 * UAshenUserWidget_TransferenceStrainHUD
 * Somatic HUD displaying Kaelen's current psychic strain stage (Flickering / Fractured / Catastrophic) and delirium warnings.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TransferenceStrainHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	ETransferenceStrainStage DisplayedStrainStage = ETransferenceStrainStage::Stable;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bIsDeliriumActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateStrainDisplay(ETransferenceStrainStage Stage, bool bDelirium);
};
