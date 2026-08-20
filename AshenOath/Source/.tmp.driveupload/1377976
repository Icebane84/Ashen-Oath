// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenBrotherMalakorGASAbility.generated.h"

/**
 * UAshenBrotherMalakorGASAbility
 * Inquisitorial radiant judgment strike and scripture flame waves.
 */
UCLASS()
class ASHENOATH_API UAshenBrotherMalakorGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenBrotherMalakorGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Boss GAS")
	float RadiantDamage = 220.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss GAS")
	bool CastRadiantScriptureStrike(AActor* TargetActor);
};
