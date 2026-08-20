// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenEmpathicConduitNovaGASAbility.generated.h"

/**
 * UAshenEmpathicConduitNovaGASAbility
 * Synchronized finisher ability unleashing 1200.0 radial damage in a 1400uu radius, gated by mutual trust >= 0.70.
 */
UCLASS()
class ASHENOATH_API UAshenEmpathicConduitNovaGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenEmpathicConduitNovaGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Nova")
	float BaseNovaDamage = 1200.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Nova")
	float NovaRadius = 1400.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Nova")
	float MinTrustRequired = 0.70f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool UnleashEmpathicNova(AActor* InstigatorActor, float CurrentMutualTrust);
};
