// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenUltimateMasterSynthesisOrchestrator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnUltimateMasterSynthesisValidatedSignature, bool, bUltimateSynthesisPassed, int32, AuditedSubsystemCount);

/**
 * UAshenUltimateMasterSynthesisOrchestrator
 *
 * Ultimate master synthesis orchestrator for Ashen Oath vertical slice.
 * Performs final audit across all 18 core game subsystems, validating complete release candidate stability.
 */
UCLASS()
class ASHENOATH_API UAshenUltimateMasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Synthesis")
	bool ExecuteUltimateMasterSynthesis();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Synthesis")
	void GenerateUltimateMasterAuditReport();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Synthesis")
	bool bUltimateSynthesisPassed = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Synthesis")
	int32 TotalAuditedSubsystems = 18;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Synthesis|Events")
	FOnUltimateMasterSynthesisValidatedSignature OnUltimateSynthesisValidated;
};
