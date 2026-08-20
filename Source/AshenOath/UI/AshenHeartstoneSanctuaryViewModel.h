// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenHeartstoneSanctuaryViewModel.generated.h"

/**
 * UAshenHeartstoneSanctuaryViewModel
 * View Model backing Screen #5: Heartstone Sanctuary ("Who do I become next?") — sacred, alive interface with floating ash, white flame, and memory fragments.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenHeartstoneSanctuaryViewModel : public UObject
{
	GENERATED_BODY()

public:
	UAshenHeartstoneSanctuaryViewModel();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	FText GoverningQuestionText = FText::FromString(TEXT("Who do I become next?"));

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | POS")
	float FloatingAshIntensity = 0.80f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | POS")
	void TriggerSanctuaryWillpowerResurgence();
};
