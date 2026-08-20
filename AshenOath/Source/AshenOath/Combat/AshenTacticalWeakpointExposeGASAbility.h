// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenTacticalWeakpointExposeGASAbility.generated.h"

/**
 * UAshenTacticalWeakpointExposeGASAbility
 * Tier II ability allowing Garrett to instantly highlight exposed dorsal vents/tethers based on learned bestiary knowledge.
 */
UCLASS()
class ASHENOATH_API UAshenTacticalWeakpointExposeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenTacticalWeakpointExposeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float VulnerabilityDamageMultiplier = 1.30f; // +30% damage to weakpoint

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExposeWeakpoint(AActor* TargetActor);
};
