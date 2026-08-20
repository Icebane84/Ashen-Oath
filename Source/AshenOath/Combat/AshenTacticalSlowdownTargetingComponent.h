// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTacticalSlowdownTargetingComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAnatomicalTargetLockedSignature, FName, WeakPointBoneName, float, CriticalDamageMultiplier);

/**
 * UAshenTacticalSlowdownTargetingComponent
 *
 * Enhanced TSC component allowing precision anatomical target lock (weak points, limbs) during slow-motion.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalSlowdownTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalSlowdownTargetingComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|TSCTargeting")
	bool LockWeakPointTarget(FName BoneName, float CritMultiplier);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TSCTargeting|Events")
	FOnAnatomicalTargetLockedSignature OnTargetLocked;

private:
	FName ActiveLockedBone = NAME_None;
};
