// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCGuardAlertnessScaleAdapterComponent.generated.h"

/**
 * UAshenNPCGuardAlertnessScaleAdapterComponent
 * Modulates town guard alertness speed based on Kaelen's Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCGuardAlertnessScaleAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCGuardAlertnessScaleAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	float GetGuardAlertnessMultiplier() const { return GuardAlertnessMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	float GuardAlertnessMultiplier = 1.0f;
};
