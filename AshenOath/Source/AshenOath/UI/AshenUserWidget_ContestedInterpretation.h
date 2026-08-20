// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ContestedInterpretation.generated.h"

/**
 * UAshenUserWidget_ContestedInterpretation
 *
 * UMG backing widget displaying contested memory text alongside raw event text during an active Interpretation Pass.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ContestedInterpretation : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayContestedInterpretation(FName MemoryID, FText RawEvent, FText ContestedText, bool bIsFragmenting);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName ActiveMemoryID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedRawEventText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FText DisplayedContestedText;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bIsActivePassFragmenting = false;
};
