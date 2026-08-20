// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CampfireInterpretiveLensMenu.generated.h"

/**
 * UAshenUserWidget_CampfireInterpretiveLensMenu
 *
 * UMG backing widget rendering Serafina's campfire lens selection UI (Accountability, Grace, Utility).
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CampfireInterpretiveLensMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateInterpretiveLensDisplay(FName SelectedLens, float CompiledMetric);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName DisplayedLensTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float DisplayedCompiledMetric = 1.0f;
};
