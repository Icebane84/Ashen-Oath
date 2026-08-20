// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenEquipmentInspectionViewModel.generated.h"

/**
 * UAshenEquipmentInspectionViewModel
 * View Model backing Screen #3: Physical Equipment ("What am I carrying?") — physical 3D inspection of weapons/armor for soot, scratches, alchemical stains, and carved notes.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenEquipmentInspectionViewModel : public UObject
{
	GENERATED_BODY()

public:
	UAshenEquipmentInspectionViewModel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	FText GoverningQuestionText = FText::FromString(TEXT("What am I carrying?"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	FName InspectedItemName = "Oathbringer";

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | POS")
	void InspectEquipmentItem(FName ItemName);
};
