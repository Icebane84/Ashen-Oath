// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Narrative/AshenEpistemicConsequenceTypes.h"
#include "AshenUserWidget_TripartiteInterpretationHUD.generated.h"

/**
 * UAshenUserWidget_TripartiteInterpretationHUD
 * Somatic UI rendering the 3 distinct handwriting styles (Kaelen charcoal, Garrett ink diagram, Serafina silver script).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TripartiteInterpretationHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FTripartiteInterpretationPackage ActivePackage;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RenderInterpretationPackage(const FTripartiteInterpretationPackage& InPackage);
};
