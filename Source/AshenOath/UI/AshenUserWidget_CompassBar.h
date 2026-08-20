// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CompassBar.generated.h"

/**
 * UAshenUserWidget_CompassBar
 *
 * UMG backing widget for the player compass / direction indicator bar.
 * Tracks current yaw heading (0–360 degrees) and converts it to a
 * normalized 0–1 scroll offset for the compass texture strip.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CompassBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateHeading(float YawDegrees);

	UFUNCTION(BlueprintPure, Category = "AshenOath|UI")
	float GetCompassScrollOffset() const { return CompassScrollOffset; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|UI")
	FText GetCardinalDirection() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CurrentYaw = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CompassScrollOffset = 0.0f;
};
