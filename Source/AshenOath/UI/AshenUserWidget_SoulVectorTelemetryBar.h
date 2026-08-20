// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenUserWidget_SoulVectorTelemetryBar.generated.h"

/**
 * UAshenUserWidget_SoulVectorTelemetryBar
 * UMG widget backing class displaying real-time FSoulStateVector telemetry.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_SoulVectorTelemetryBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateTelemetryDisplay(const FSoulStateVector& StateVector);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	float GetCachedIsolationPct() const { return CachedIsolation; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|UI")
	float CachedIsolation = 0.0f;
};
