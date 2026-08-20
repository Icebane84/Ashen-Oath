// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenPredatorDarkSurgeGASAbility.generated.h"

/**
 * UAshenPredatorDarkSurgeGASAbility
 * Raw offensive strike compiled by the Lens of Utility (+15% dark power, adds +5.0 soot stain to armor).
 */
UCLASS()
class ASHENOATH_API UAshenPredatorDarkSurgeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenPredatorDarkSurgeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float DarkPowerDamageBonusRatio = 0.15f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SootStainPenalty = 5.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteDarkSurge(float& OutSootAdded);
};
