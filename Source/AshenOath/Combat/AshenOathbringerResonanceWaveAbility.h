// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenOathbringerResonanceWaveAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerResonanceWaveExecutedSignature, FVector, ShockwaveDirection, float, ResonanceDamage);

/**
 * UAshenOathbringerResonanceWaveAbility
 *
 * Ability releasing a shockwave of stored holy light along the blade's edge (PRS-001 Oathbringer Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenOathbringerResonanceWaveAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|OathbringerAbilities")
	void ExecuteResonanceWave(FVector Direction, float BaseDamage = 300.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|OathbringerAbilities|Events")
	FOnOathbringerResonanceWaveExecutedSignature OnResonanceWaveExecuted;
};
