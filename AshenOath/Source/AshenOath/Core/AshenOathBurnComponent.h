// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathBurnComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathBurnActivatedSignature, float, DamageMultiplier, float, MaxHealthBurnAmount);

/**
 * UAshenOathBurnComponent
 *
 * Oath Burn system component managing character sacrifice of Oath charges for 2.5x damage spikes + temporary maximum health burn penalty.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathBurnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathBurnComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|OathBurn")
	bool TriggerOathBurn();

	UFUNCTION(BlueprintPure, Category = "AshenOath|OathBurn")
	bool IsOathBurnActive() const { return bIsOathBurnActive; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|OathBurn")
	float GetDamageMultiplier() const { return bIsOathBurnActive ? 2.5f : 1.0f; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|OathBurn")
	float MaxHealthBurnPenalty = 25.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|OathBurn|Events")
	FOnOathBurnActivatedSignature OnOathBurnActivated;

private:
	bool bIsOathBurnActive = false;
};
