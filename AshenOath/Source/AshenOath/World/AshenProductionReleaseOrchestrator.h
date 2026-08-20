// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenProductionReleaseOrchestrator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProductionReleaseValidatedSignature, bool, bReleaseReady, int32, AuditedSubsystemCount);

/**
 * UAshenProductionReleaseOrchestrator
 *
 * Master production release orchestrator for Ashen Oath vertical slice.
 * Audits end-to-end subsystem health (14/14 subsystems), verifies save game state integrity,
 * and manages level transition pipelines.
 */
UCLASS()
class ASHENOATH_API UAshenProductionReleaseOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Release")
	bool ValidateReleaseIntegrity();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Release")
	void GenerateReleaseAuditReport();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Release")
	bool bReleaseReady = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Release")
	int32 TotalAuditedSubsystems = 14;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Release|Events")
	FOnProductionReleaseValidatedSignature OnReleaseValidated;
};
