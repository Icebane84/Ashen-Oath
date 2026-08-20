// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenSerafinaSunPulseSanctuaryAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSunPulseExecutedSignature, float, RestoredWillpower, float, BlindDurationSeconds);

/**
 * UAshenSerafinaSunPulseSanctuaryAbility
 *
 * Ability emitting pulse waves that blind void enemies and restore Kaelen's willpower (PRS-001 Serafina Slice).
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSerafinaSunPulseSanctuaryAbility : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaAbilities")
	void ExecuteSunPulseSanctuary(float BaseWillpowerRestoration = 30.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaAbilities|Events")
	FOnSunPulseExecutedSignature OnSunPulseExecuted;
};
