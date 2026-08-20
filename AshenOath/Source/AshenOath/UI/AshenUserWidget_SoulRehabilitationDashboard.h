// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SoulRehabilitationDashboard.generated.h"

/**
 * UAshenUserWidget_SoulRehabilitationDashboard
 * UMG interactive dashboard visualizing trait alignment shifts during rehabilitation.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SoulRehabilitationDashboard : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float PurityPercentage = 1.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 RemainingImprints = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshDashboard(float Purity, int32 Imprints);
};
