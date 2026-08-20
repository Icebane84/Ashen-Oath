// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenGrandMasterSynthesisOrchestrator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGrandMasterSynthesisValidatedSignature, bool, bSynthesisPassed, int32, AuditedSubsystemCount);

/**
 * UAshenGrandMasterSynthesisOrchestrator
 *
 * Grand master synthesis orchestrator for Ashen Oath.
 * Audits end-to-end subsystem health across all 16 core subsystems, verifying ultimate release readiness.
 */
UCLASS()
class ASHENOATH_API UAshenGrandMasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Synthesis")
	bool ExecuteGrandMasterSynthesis();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Synthesis")
	void GenerateGrandMasterAuditReport();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Synthesis")
	bool bSynthesisPassed = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Synthesis")
	int32 TotalAuditedSubsystems = 16;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Synthesis|Events")
	FOnGrandMasterSynthesisValidatedSignature OnSynthesisValidated;
};
