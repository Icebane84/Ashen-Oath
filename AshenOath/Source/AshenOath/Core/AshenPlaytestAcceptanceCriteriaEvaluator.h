// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenPlaytestAcceptanceCriteriaEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlaytestCriteriaEvaluatedSignature, FName, ObservationCategory, bool, bCriteriaMet);

/**
 * UAshenPlaytestAcceptanceCriteriaEvaluator
 *
 * Subsystem evaluating playtest qualitative metrics (PRS-001 Combat Blueprint V5.0 VII. Playtest Acceptance Criteria).
 */
UCLASS()
class ASHENOATH_API UAshenPlaytestAcceptanceCriteriaEvaluator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PlaytestCriteria")
	bool EvaluatePlaytestCriteria(FName ObservationCategory, float PhysicalTensionRating);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PlaytestCriteria|Events")
	FOnPlaytestCriteriaEvaluatedSignature OnCriteriaEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PlaytestCriteria")
	int32 TotalCriteriaVerified = 5;
};
