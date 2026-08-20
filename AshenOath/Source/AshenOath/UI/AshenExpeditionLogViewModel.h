// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenExpeditionLogViewModel.generated.h"

/**
 * UAshenExpeditionLogViewModel
 * View Model backing Screen #1: Expedition Log ("What have we learned?") — physical leather-bound book, handwriting styles, ink smears, and physical margins.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenExpeditionLogViewModel : public UObject
{
	GENERATED_BODY()

public:
	UAshenExpeditionLogViewModel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	FText GoverningQuestionText = FText::FromString(TEXT("What have we learned?"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	float HandwritingJaggedness = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | POS")
	void UpdateHandwritingFromIntegrationDebt(float IntegrationDebt);
};
