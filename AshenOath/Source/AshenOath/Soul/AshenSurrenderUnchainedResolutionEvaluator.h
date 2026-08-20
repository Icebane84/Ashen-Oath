// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSurrenderUnchainedResolutionEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSurrenderUnchainedExecutedSignature, FName, AppliedStanceTag, float, AttackSpeedMultiplier);

/**
 * UAshenSurrenderUnchainedResolutionEvaluator
 *
 * Subsystem executing Dark Mode surrender resolution (black tendril snap, screen tear, Stance.UnchainedBerserk, trust atrophy) (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenSurrenderUnchainedResolutionEvaluator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SurrenderResolution")
	void ExecuteSurrenderUnchainedResolution();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SurrenderResolution|Events")
	FOnSurrenderUnchainedExecutedSignature OnSurrenderExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SurrenderResolution")
	int32 TotalSurrendersExecuted = 0;
};
