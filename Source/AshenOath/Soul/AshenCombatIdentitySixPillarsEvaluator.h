// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenCombatIdentitySixPillarsEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSixPillarsEvaluatedSignature, FName, PillarTag, bool, bPillarSatisfied);

/**
 * UAshenCombatIdentitySixPillarsEvaluator
 *
 * Subsystem evaluating combat actions against the Six Pillars of Combat Identity (PRS-001 Combat Blueprint V5.0).
 */
UCLASS()
class ASHENOATH_API UAshenCombatIdentitySixPillarsEvaluator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SixPillars")
	bool EvaluateCombatPillarCompliance(FName ActionTag, bool bIsDisciplinedTiming);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SixPillars|Events")
	FOnSixPillarsEvaluatedSignature OnPillarEvaluated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SixPillars")
	int32 TotalPillarsPassed = 6;
};
