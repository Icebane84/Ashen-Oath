// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenResistWillpowerResolutionEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnResistWillpowerExecutedSignature, FName, AppliedStateTag, bool, bFullStaminaRestored);

/**
 * UAshenResistWillpowerResolutionEvaluator
 *
 * Subsystem executing Resistance resolution (glass shatter, silver dust VFX, bell tone, State.Willpower.Unbroken, full stamina restore) (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenResistWillpowerResolutionEvaluator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResistResolution")
	void ExecuteResistWillpowerResolution();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResistResolution|Events")
	FOnResistWillpowerExecutedSignature OnResistExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ResistResolution")
	int32 TotalResistancesExecuted = 0;
};
