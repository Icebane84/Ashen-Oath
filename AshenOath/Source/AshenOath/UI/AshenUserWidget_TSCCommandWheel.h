// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_TSCCommandWheel.generated.h"

/**
 * UAshenUserWidget_TSCCommandWheel
 *
 * UMG backing widget rendering the Tactical Slowdown companion command wheel and Command Strain gauges.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_TSCCommandWheel : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void DisplayTSCCommandWheel(bool bInWheelActive, float TimeDilation);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bTSCWheelActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float ActiveDilation = 1.0f;
};
