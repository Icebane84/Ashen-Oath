// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMalakorVoidSmashBossPhaseController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMalakorVoidSmashExecutedSignature, FVector, ImpactLocation, float, VoidSmashDamage);

/**
 * UAshenMalakorVoidSmashBossPhaseController
 *
 * Boss phase controller for Abomination Malakor's Void Smash attacks (Where Light Fades Act 01).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMalakorVoidSmashBossPhaseController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMalakorVoidSmashBossPhaseController();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MalakorBoss")
	void ExecuteVoidSmash(FVector ImpactTarget, float BaseSmashDamage = 350.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MalakorBoss|Events")
	FOnMalakorVoidSmashExecutedSignature OnVoidSmashExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MalakorBoss")
	int32 TotalSmashesExecuted = 0;
};
