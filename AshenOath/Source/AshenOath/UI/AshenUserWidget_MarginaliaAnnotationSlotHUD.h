// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenUserWidget_MarginaliaAnnotationSlotHUD.generated.h"

/**
 * UAshenUserWidget_MarginaliaAnnotationSlotHUD
 * 
 * Individual anchor slot widget rendering a single companion marginalia entry:
 * - Font styling and ink color
 * - Strike-through crossout overlay
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_MarginaliaAnnotationSlotHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_MarginaliaAnnotationSlotHUD(const FObjectInitializer& ObjectInitializer);

	/** Configures slot with marginalia data */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Marginalia")
	void ConfigureSlot(const FMarginaliaEntry& Entry);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Marginalia")
	EMarginAnchorSlot GetSlotType() const { return CurrentSlot; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Marginalia")
	FMarginaliaEntry CurrentEntry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Marginalia")
	EMarginAnchorSlot CurrentSlot = EMarginAnchorSlot::RightMargin_Lower;
};
