// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDevilsBargainHesitationProtocolEvaluator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHesitationOutcomeEvaluatedSignature, FName, OutcomeTag, bool, bWhiteFlameSurgeGranted);

/**
 * UAshenDevilsBargainHesitationProtocolEvaluator
 *
 * Subsystem evaluating prompt window timeout: Martyr's Guard ally step-in vs Solo Inaction severe poise damage (PRS-001 Combat Blueprint V5.0).
 */
UCLASS()
class ASHENOATH_API UAshenDevilsBargainHesitationProtocolEvaluator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|HesitationProtocol")
	FName EvaluateHesitationOutcome(bool bIsAllyNearby);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|HesitationProtocol|Events")
	FOnHesitationOutcomeEvaluatedSignature OnOutcomeEvaluated;
};
