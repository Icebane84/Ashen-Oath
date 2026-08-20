// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenFocusModeInvestigationComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFocusModeStateChangedSignature, bool, bIsFocusActive, float, InvestigationRange);

/**
 * UAshenFocusModeInvestigationComponent
 *
 * Component enabling Kaelen's Focus Mode for inspecting hidden memory trails and distorted investigative clues.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFocusModeInvestigationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFocusModeInvestigationComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|FocusMode")
	void ToggleFocusMode(bool bEnable);

	UFUNCTION(BlueprintPure, Category = "AshenOath|FocusMode")
	bool IsFocusModeActive() const { return bFocusModeActive; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FocusMode|Events")
	FOnFocusModeStateChangedSignature OnFocusModeStateChanged;

private:
	bool bFocusModeActive = false;
};
