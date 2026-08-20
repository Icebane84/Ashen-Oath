// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_ArmorCorrosionInspector.generated.h"

/**
 * UAshenUserWidget_ArmorCorrosionInspector
 * UMG backing widget presenting diegetic armor wear, corrosion scuff maps, and physical integrity telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_ArmorCorrosionInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	float ArmorCorrosionPercent = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshArmorCorrosionDisplay(float CorrosionLevel);
};
