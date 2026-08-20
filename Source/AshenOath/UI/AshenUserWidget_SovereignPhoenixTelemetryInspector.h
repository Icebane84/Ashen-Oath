// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_SovereignPhoenixTelemetryInspector.generated.h"

/**
 * UAshenUserWidget_SovereignPhoenixTelemetryInspector
 * UMG backing widget rendering live telemetry of sovereign Phoenix perks, active blessings, and state vector metrics.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SovereignPhoenixTelemetryInspector : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | UI")
	int32 ActivePhoenixPerkCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | UI")
	void RefreshPhoenixTelemetryDisplay(int32 PerkCount);
};
