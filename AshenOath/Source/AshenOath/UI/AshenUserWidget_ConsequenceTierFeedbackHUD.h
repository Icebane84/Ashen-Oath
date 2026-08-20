// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenUserWidget_ConsequenceTierFeedbackHUD.generated.h"

/**
 * UAshenUserWidget_ConsequenceTierFeedbackHUD
 * Somatic HUD widget presenting non-intrusive feedback when a consequence tier resolves.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ConsequenceTierFeedbackHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EConsequenceProfileTier ActiveTier = EConsequenceProfileTier::Common;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FName DisplayedEncounterName = NAME_None;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void DisplayTierFeedback(EConsequenceProfileTier InTier, FName InEncounter);
};
