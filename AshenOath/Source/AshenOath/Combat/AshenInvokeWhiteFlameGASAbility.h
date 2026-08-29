// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "Combat/AshenWhiteFlameTypes.h"
#include "AshenInvokeWhiteFlameGASAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnWhiteFlameInvokedSignature, float, ClearedDebt, float, SanityHealed, float, Duration);

/**
 * UAshenInvokeWhiteFlameGASAbility
 * Ultimate GAS ability activating the White Flame Resolution state, transmuting Nyxian sap into White Pyre-Aether and eradicating all Integration Debt.
 */
UCLASS()
class ASHENOATH_API UAshenInvokeWhiteFlameGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenInvokeWhiteFlameGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float CatharsisDurationSeconds = 12.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float SanityHealAmount = 50.0f;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | WhiteFlame|Events")
	FOnWhiteFlameInvokedSignature OnWhiteFlameInvoked;

	/** Executes the complete White Flame Resolution payload */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	bool InvokeWhiteFlame(AActor* KaelenActor, AActor* SerafinaActor, float KaelenResolve = 1.0f, float SerafinaBurnout = 0.80f);
};
