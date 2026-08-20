// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenGASAbilityCooldownStateAdapterComponent.generated.h"

/**
 * UAshenGASAbilityCooldownStateAdapterComponent
 * Scales GAS ability cooldown timers based on IntegrationDebt.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGASAbilityCooldownStateAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenGASAbilityCooldownStateAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Combat")
	float GetCooldownMultiplier() const { return CooldownMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Combat")
	float CooldownMultiplier = 1.0f;
};
