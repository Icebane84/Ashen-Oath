// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenWeaveAegisNetGASAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnAegisNetDeployedSignature, AActor*, TargetCharacter, float, Duration, float, FatigueCost);

/**
 * UAshenWeaveAegisNetGASAbility
 * GAS ability allowing Serafina to weave a reactive golden net of light across Kaelen's posture
 * (6.0s duration, grants HyperArmor on PoiseComponent, adds +0.15 Serafina fatigue).
 */
UCLASS()
class ASHENOATH_API UAshenWeaveAegisNetGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWeaveAegisNetGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float AegisDurationSeconds = 6.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float SerafinaFatigueCost = 0.15f;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Weaving|Events")
	FOnAegisNetDeployedSignature OnAegisNetDeployed;

	/** Deploys the protective aegis net onto the target character */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	bool DeployAegisNetOnTarget(AActor* TargetCharacter);
};
