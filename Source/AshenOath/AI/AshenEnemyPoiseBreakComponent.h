// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnemyPoiseBreakComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPoiseBrokenSignature, AActor*, StaggeredEnemy);

/**
 * UAshenEnemyPoiseBreakComponent
 *
 * Dynamic staggering component managing posture break thresholds and execution state windows.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEnemyPoiseBreakComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEnemyPoiseBreakComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PoiseBreak")
	float ApplyPoiseDamage(float PoiseDamageAmount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|PoiseBreak")
	bool IsPoiseBroken() const { return bIsPoiseBroken; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PoiseBreak|Events")
	FOnPoiseBrokenSignature OnPoiseBroken;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|PoiseBreak")
	float MaxPoise = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PoiseBreak")
	float CurrentPoise = 100.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PoiseBreak")
	bool bIsPoiseBroken = false;
};
