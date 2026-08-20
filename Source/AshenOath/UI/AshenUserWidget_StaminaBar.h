// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_StaminaBar.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExhaustionPulseSignature);

/**
 * UAshenUserWidget_StaminaBar
 *
 * UMG backing widget for the player stamina bar.
 * Tracks current stamina percentage and broadcasts an exhaustion
 * pulse delegate when stamina is fully depleted for UI flash feedback.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_StaminaBar : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateStamina(float CurrentStamina, float MaxStamina);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void TriggerExhaustionPulse();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CurrentStaminaPercent = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	bool bIsExhausted = false;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|UI|Events")
	FOnExhaustionPulseSignature OnExhaustionPulse;
};
