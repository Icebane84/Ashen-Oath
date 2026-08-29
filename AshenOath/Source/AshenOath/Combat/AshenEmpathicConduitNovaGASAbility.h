// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenEmpathicConduitNovaGASAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnEmpathicNovaUnleashedSignature, float, ActualDamageDealt, float, Radius, float, ActiveTrust);

/**
 * UAshenEmpathicConduitNovaGASAbility
 * Synchronized tripartite finisher ability unleashing 1200.0 radial damage in a 1400uu radius,
 * scaled by mutual companion trust (gated by Trust >= 70.0%).
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
	float BasePoiseDamage = 300.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Nova")
	float NovaRadius = 1400.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Nova")
	float MinTrustRequired = 0.70f;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Nova|Events")
	FOnEmpathicNovaUnleashedSignature OnEmpathicNovaUnleashed;

	/** Unleashes the tripartite conduit nova, pulling active trust from the Trust Director if OverrideTrust < 0 */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool UnleashEmpathicNova(AActor* InstigatorActor, float OverrideTrust = -1.0f);
};
