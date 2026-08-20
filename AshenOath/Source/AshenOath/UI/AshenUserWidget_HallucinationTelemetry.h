// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_HallucinationTelemetry.generated.h"

/**
 * UAshenUserWidget_HallucinationTelemetry
 * Debug/telemetry UMG widget visualizing active environmental distortion factor and phantom count.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_HallucinationTelemetry : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActiveHallucinationStateEnum = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActivePhantomCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void UpdateHallucinationTelemetry(int32 StateEnum, int32 Phantoms);
};
