// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Companions/AshenSomaticSilenceTypes.h"
#include "AshenSomaticSilenceSubsystem.generated.h"

class UAshenSilenceClassifierComponent;
class UAshenWordlessSupportEvaluatorComponent;
class UAshenBoundaryRefusalEvaluatorComponent;

/**
 * UAshenSomaticSilenceSubsystem
 * 
 * Central world subsystem coordinating real-time silence classification,
 * wordless proactive companion assistance, and boundary refusal events.
 */
UCLASS()
class ASHENOATH_API UAshenSomaticSilenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenSomaticSilenceSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Classifies player silence based on context, dysregulation, and combat recency */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Silence")
	FSilenceEvaluationSnapshot EvaluatePlayerSilence(
		float SilenceDuration,
		float CombatRecencySeconds,
		float AccumulatedDysregulation,
		bool bActiveMemoryTrigger);

	/** Evaluates whether high-trust companion should execute wordless assistance */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Silence")
	FWordlessSupportCommand EvaluateWordlessSupport(
		FName CompanionName,
		float CompanionTrust,
		const FVector& KaelenLocation,
		const FVector& NearestObstacleLocation);

	/** Evaluates whether companion should refuse to follow into self-destruction */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Silence")
	ECompanionBoundaryState EvaluateBoundaryRefusal(
		FName CompanionName,
		float CompanionTrust,
		float KaelenDysregulation,
		bool bIsSuicidalCharge);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Silence")
	FOnSilenceClassified OnSilenceClassified;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Silence")
	FOnWordlessSupportDispatched OnWordlessSupportDispatched;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Silence")
	FOnBoundaryRefusalTriggered OnBoundaryRefusalTriggered;

protected:
	UPROPERTY()
	UAshenSilenceClassifierComponent* SilenceClassifier;

	UPROPERTY()
	UAshenWordlessSupportEvaluatorComponent* WordlessEvaluator;

	UPROPERTY()
	UAshenBoundaryRefusalEvaluatorComponent* BoundaryEvaluator;
};
