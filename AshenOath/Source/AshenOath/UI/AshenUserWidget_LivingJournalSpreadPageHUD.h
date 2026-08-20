// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "AshenUserWidget_LivingJournalSpreadPageHUD.generated.h"

/**
 * UAshenUserWidget_LivingJournalSpreadPageHUD
 * 
 * Master Living Journal UI Spread Page:
 * - Base Canvas with dynamic parchment lighting
 * - Kaelen's core text layer
 * - Left and Right margin annotation slots
 * - Footer scratch-out / botanical pressing area
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_LivingJournalSpreadPageHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UAshenUserWidget_LivingJournalSpreadPageHUD(const FObjectInitializer& ObjectInitializer);

	/** Populates spread page with authoritative entries */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void PopulateJournalPage(
		const FString& CoreText,
		const TArray<FMarginaliaEntry>& MarginaliaEntries,
		float InkJitterIntensity);

	/** Clears page spread */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Journal")
	void ClearJournalPage();

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Journal")
	const TArray<FMarginaliaEntry>& GetActiveMarginalia() const { return ActiveEntries; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	FString KaelenCoreProse;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	TArray<FMarginaliaEntry> ActiveEntries;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Journal")
	float CurrentJitterIntensity = 0.0f;
};
