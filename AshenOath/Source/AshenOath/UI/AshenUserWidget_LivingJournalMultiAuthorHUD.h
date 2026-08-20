// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "AshenUserWidget_LivingJournalMultiAuthorHUD.generated.h"

/**
 * UAshenUserWidget_LivingJournalMultiAuthorHUD
 * 
 * Multi-author UMG Widget rendering:
 * - Kaelen's trauma prose on the left page
 * - Garrett's tactical charcoal diagrams in the upper margin
 * - Serafina's botanical silverleaf pressings and empathic reflections in the lower corner
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LivingJournalMultiAuthorHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_LivingJournalMultiAuthorHUD(const FObjectInitializer& ObjectInitializer);

	/** Populates the journal spread with multi-authored entries */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void DisplayJournalSpread(
		const FText& KaelenText,
		const FText& GarrettMarginNote,
		const FText& SerafinaReflection,
		float SootStainIntensity);

	/** Sets visual opacity for individual author layer */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void SetAuthorLayerOpacity(EAuthorIdentity Author, float Opacity);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Journal")
	float GetSootIntensity() const { return CurrentSootIntensity; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	FText KaelenProse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	FText GarrettDiagramText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	FText SerafinaReflectionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	float CurrentSootIntensity = 0.0f;
};
