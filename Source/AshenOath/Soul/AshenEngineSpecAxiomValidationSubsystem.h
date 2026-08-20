// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenEngineSpecAxiomValidationSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEngineAxiomValidatedSignature, FName, AxiomID, bool, bIsCoherent);

/**
 * UAshenEngineSpecAxiomValidationSubsystem
 *
 * World Subsystem validating Axiom II sibling rule across all state vectors:
 * "The Soul Constellation does not remember what happened. It remembers what the experience became."
 */
UCLASS()
class ASHENOATH_API UAshenEngineSpecAxiomValidationSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EngineSpec")
	bool ValidateAxiomIISiblingRuleCoherence();

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EngineSpec|Events")
	FOnEngineAxiomValidatedSignature OnAxiomValidated;
};
