// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenUnchainedBerserkGASAbility.generated.h"

/**
 * UAshenUnchainedBerserkGASAbility
 * Activates unchained berserk stance, hyper-armor poise, scaling attack power at cost of soul health.
 */
UCLASS()
class ASHENOATH_API UAshenUnchainedBerserkGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenUnchainedBerserkGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float AttackMultiplier = 2.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float PoiseHyperArmorMultiplier = 3.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ActivateUnchainedBerserk();
};
