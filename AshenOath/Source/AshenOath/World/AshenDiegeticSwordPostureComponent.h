// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticSwordPostureComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSwordPostureStateChangedSignature, FName, PostureStanceTag, float, ParryWindowMultiplier);

/**
 * UAshenDiegeticSwordPostureComponent
 *
 * Diegetic sword posture component projecting into 3 distinct layers under Constitutional Law #491:
 * Layer 1 (Combat): Parry window multiplier scaling with posture readiness.
 * Layer 2 (Animation): Sword guard stance animation blending.
 * Layer 3 (Dialogue): Companion posture observation bark (e.g., Serafina: "His posture is firm.").
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticSwordPostureComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticSwordPostureComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SwordPosture")
	void SetPostureStance(FName StanceTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SwordPosture|Events")
	FOnSwordPostureStateChangedSignature OnPostureStanceChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SwordPosture")
	FName CurrentStanceTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SwordPosture")
	float CalculatedParryWindowMultiplier = 1.0f;
};
