// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDualMirrorCompilerPassOrchestrator.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnDualMirrorPassOrchestratedSignature, FName, MemoryID, float, IntegrationBalance, float, EntropyErosion);

/**
 * UAshenDualMirrorCompilerPassOrchestrator
 *
 * Orchestrator coordinating the dual Integrative vs Fragmentation passes across the Memory Palace graph (UMB-INT-001).
 */
UCLASS()
class ASHENOATH_API UAshenDualMirrorCompilerPassOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|DualMirrorCompiler")
	void OrchestrateDualPasses(FName MemoryID, float IntegrationStrength, float VoidErosionStrength);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DualMirrorCompiler|Events")
	FOnDualMirrorPassOrchestratedSignature OnPassOrchestrated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|DualMirrorCompiler")
	int32 TotalDualPassesOrchestrated = 0;
};
