// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenUserWidget_RelationalTriageHUD.generated.h"

/**
 * UAshenUserWidget_RelationalTriageHUD
 * Interactive dialogue lens selector UI displaying Accountability, Grace, and Utility pathways during campfire triage.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_RelationalTriageHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EInterpretiveTherapyLens SelectedLens = EInterpretiveTherapyLens::Grace;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void SelectLensOption(EInterpretiveTherapyLens Lens);
};
