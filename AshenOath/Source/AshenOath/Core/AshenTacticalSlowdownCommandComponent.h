// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTacticalSlowdownCommandComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTSCSlowdownStateChangedSignature, bool, bIsSlowdownActive, float, TimeDilationDilationFactor);

/**
 * UAshenTacticalSlowdownCommandComponent
 *
 * Tactical Slowdown & Command (TSC) System component allowing Kaelen to enter brief 0.2x slow-motion to issue companion commands.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTacticalSlowdownCommandComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTacticalSlowdownCommandComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|TSC")
	bool ActivateTacticalSlowdown();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|TSC")
	void DeactivateTacticalSlowdown();

	UFUNCTION(BlueprintPure, Category = "AshenOath|TSC")
	bool IsSlowdownActive() const { return bSlowdownActive; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|TSC")
	float SlowdownDilationScale = 0.20f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TSC|Events")
	FOnTSCSlowdownStateChangedSignature OnSlowdownStateChanged;

private:
	bool bSlowdownActive = false;
};
