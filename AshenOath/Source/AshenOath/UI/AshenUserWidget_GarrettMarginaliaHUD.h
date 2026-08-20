// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_GarrettMarginaliaHUD.generated.h"

/**
 * UAshenUserWidget_GarrettMarginaliaHUD
 * Somatic UI widget rendering Garrett's dynamic handwriting, sketches, and tactical margin notes based on TAM-001 trust levels.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_GarrettMarginaliaHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	FString MarginaliaText = TEXT("Make sure the shear pins are snug.");

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	bool bShowFriendlyDoodles = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateMarginaliaForTrust(float TrustScore);
};
