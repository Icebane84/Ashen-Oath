// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenTransferenceMirrorGASAbility.generated.h"

/**
 * UAshenTransferenceMirrorGASAbility
 * Serafina's emergency heal ability governed by Equivalent Exchange, mending target health while inflicting physiological Empathic Burnout.
 */
UCLASS()
class ASHENOATH_API UAshenTransferenceMirrorGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenTransferenceMirrorGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Transference")
	float BaseHealingAmount = 450.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Transference")
	float BurnoutIncurredPercent = 0.25f; // +25% burnout per cast

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Transference")
	bool ExecuteTransferenceHeal(AActor* InstigatorActor, AActor* TargetHero);
};
