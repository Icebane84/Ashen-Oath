// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Companions/AshenTransferenceBurnoutTypes.h"
#include "AshenEmpathicTransferenceSubsystem.generated.h"

class UAshenSerafinaBurnoutReceiverComponent;
class UAshenStaggerResolutionEvaluatorComponent;
class UAshenShadowOveruseAuditorComponent;

/**
 * UAshenEmpathicTransferenceSubsystem
 * 
 * Central world subsystem coordinating Serafina's somatic transference costs,
 * companion moral evaluations on staggered foes, and shadow mark overuse audits.
 */
UCLASS()
class ASHENOATH_API UAshenEmpathicTransferenceSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenEmpathicTransferenceSubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Processes healing transference absorbed by Serafina */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Transference")
	FTransferenceBurdenSnapshot ProcessEmpathicTransference(float RawTraumaAmount);

	/** Evaluates mercy vs execution choice */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Transference")
	FMercyExecutionEvaluationResult EvaluateStaggerResolution(
		EFoeStaggerResolutionChoice ChoiceMade,
		bool bTargetIsHumanoid,
		float TargetThreatLevel);

	/** Audits shadow mark ability usage */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Companions|Transference")
	EShadowMarkOveruseResponse RecordShadowAbilityUsage(float CorruptionCost);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Companions|Transference")
	FOnTransferenceAbsorbed OnTransferenceAbsorbed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Companions|Transference")
	FOnStaggerResolutionEvaluated OnStaggerResolutionEvaluated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Companions|Transference")
	FOnBurnoutTierChanged OnBurnoutTierChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Companions|Transference")
	FOnShadowOveruseInterventionTriggered OnShadowOveruseInterventionTriggered;

protected:
	UPROPERTY()
	UAshenSerafinaBurnoutReceiverComponent* BurnoutReceiver;

	UPROPERTY()
	UAshenStaggerResolutionEvaluatorComponent* StaggerEvaluator;

	UPROPERTY()
	UAshenShadowOveruseAuditorComponent* ShadowAuditor;
};
