// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFocusModeInvestigationComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFocusModeStateChangedSignature, bool, bIsFocusActive, float, InvestigationRange);

/**
 * UAshenFocusModeInvestigationComponent
 *
 * Component enabling Kaelen's Focus Mode for inspecting hidden memory trails, scanning enemy weakpoints,
 * and slowing time to 0.35x while draining sanity at 4.0 units/second.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFocusModeInvestigationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFocusModeInvestigationComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Enables or disables Focus Mode perception dilation and sanity drain */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|FocusMode")
	void ToggleFocusMode(bool bEnable);

	UFUNCTION(BlueprintPure, Category = "AshenOath|FocusMode")
	bool IsFocusModeActive() const { return bFocusModeActive; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|FocusMode")
	float GetTimeDilationMultiplier() const { return TimeDilationMultiplier; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FocusMode|Events")
	FOnFocusModeStateChangedSignature OnFocusModeStateChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|FocusMode")
	float TimeDilationMultiplier = 0.35f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|FocusMode")
	float SanityDrainRate = 4.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|FocusMode")
	float InvestigationRange = 1200.0f;

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|FocusMode")
	bool bFocusModeActive = false;
};
