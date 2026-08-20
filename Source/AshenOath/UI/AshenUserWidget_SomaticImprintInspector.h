// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SomaticImprintInspector.generated.h"

/**
 * UAshenUserWidget_SomaticImprintInspector
 * UMG backing widget rendering qualitative somatic scar imprints in the journal.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SomaticImprintInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActiveImprintCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshSomaticImprintsDisplay(int32 ImprintCount);
};
