// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenUserWidget_PsychicDialogueWheelHUD.generated.h"

/**
 * UAshenUserWidget_PsychicDialogueWheelHUD
 * Somatic dialogue selection wheel displaying active psychological tone (Resolute, Cynical, Despairing, Enlightened) and gated choices.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_PsychicDialogueWheelHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	EPsychologicalTone DisplayedTone = EPsychologicalTone::Resolute;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 AvailableChoiceCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateDialogueWheel(EPsychologicalTone InTone, int32 InChoices);
};
