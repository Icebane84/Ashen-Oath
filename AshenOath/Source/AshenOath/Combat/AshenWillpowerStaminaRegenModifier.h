// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenWillpowerStaminaRegenModifier.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStaminaRegenModifiedSignature, float, NewRegenRate, bool, bInstantReplenishApplied);

/**
 * UAshenWillpowerStaminaRegenModifier
 *
 * Modifier applying +50% stamina recovery and instant full replenishment under State.Willpower.Unbroken (PRS-001 Combat Blueprint).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenWillpowerStaminaRegenModifier : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|WillpowerStamina")
	float ModifyStaminaRegenRate(float BaseRegenRate, bool bIsUnbrokenActive);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WillpowerStamina|Events")
	FOnStaminaRegenModifiedSignature OnStaminaRegenModified;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WillpowerStamina")
	float ActiveRegenRate = 10.0f;
};
