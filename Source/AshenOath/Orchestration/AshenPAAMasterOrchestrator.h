// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenPAAMasterOrchestrator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPAAAuditExecutedSignature, FName, AuditPhaseTag, bool, bIsAuditClean);

/**
 * UAshenPAAMasterOrchestrator
 *
 * Production Architecture Audit Master Orchestrator managing subsystem lifecycles.
 */
UCLASS()
class ASHENOATH_API UAshenPAAMasterOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PAA")
	bool RunProductionArchitectureAuditPass(FName AuditPhaseTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PAA|Events")
	FOnPAAAuditExecutedSignature OnPAAAuditExecuted;
};
