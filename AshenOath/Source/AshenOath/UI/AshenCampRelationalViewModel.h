// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenCampRelationalViewModel.generated.h"

/**
 * UAshenCampRelationalViewModel
 * View Model backing Screen #2: Camp / Relationships ("How are we doing?") — spatial view of Garrett cleaning traps, Serafina reading, and Kaelen at the fire.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenCampRelationalViewModel : public UObject
{
	GENERATED_BODY()

public:
	UAshenCampRelationalViewModel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	FText GoverningQuestionText = FText::FromString(TEXT("How are we doing?"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	FName SelectedCampCompanion = "Garrett";

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | POS")
	void SelectCompanionProfile(FName CompanionName);
};
