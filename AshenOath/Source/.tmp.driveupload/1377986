// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenInvokeWhiteFlameGASAbility.generated.h"

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

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	bool InvokeWhiteFlame(AActor* KaelenActor, AActor* SerafinaActor);
};
