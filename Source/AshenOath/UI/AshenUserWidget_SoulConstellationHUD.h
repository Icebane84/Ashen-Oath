// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Companions/AshenRelationalTriageTypes.h"
#include "AshenUserWidget_SoulConstellationHUD.generated.h"

/**
 * UAshenUserWidget_SoulConstellationHUD
 * UI rendering the 3-node soul constellation graph and showing real-time displacement between Kaelen, Serafina, and Garrett.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SoulConstellationHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float CurrentNodeDistance = 250.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateConstellationDisplay(float NodeDistance);
};
