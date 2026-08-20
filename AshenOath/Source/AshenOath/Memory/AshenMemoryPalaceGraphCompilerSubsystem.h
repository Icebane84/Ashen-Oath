// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMemoryPalaceGraphCompilerSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMemoryGraphCompiledSignature, int32, ActiveNodeCount, float, ConstellationCoherencePercent);

/**
 * UAshenMemoryPalaceGraphCompilerSubsystem
 *
 * Subsystem resolving active memory nodes into level navigation & constellation paths (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API UAshenMemoryPalaceGraphCompilerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MemoryGraph")
	void CompileMemoryConstellationGraph(int32 UnlockedNodesCount);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MemoryGraph|Events")
	FOnMemoryGraphCompiledSignature OnMemoryGraphCompiled;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MemoryGraph")
	float ActiveGraphCoherence = 100.0f;
};
