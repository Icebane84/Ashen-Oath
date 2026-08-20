// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenIntegrativeMemoryPassCompilerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIntegrativeMemoryPassCompiledSignature, int32, NodesAlignedCount, float, IntegrationClarityPercent);

/**
 * UAshenIntegrativeMemoryPassCompilerComponent
 *
 * Mirror-compiler component executing integrative memory alignment passes (UMB-INT-001 Memory Slice).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIntegrativeMemoryPassCompilerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenIntegrativeMemoryPassCompilerComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|IntegrativeMemory")
	void ExecuteIntegrativeMemoryPass(int32 TargetNodesToAlign);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|IntegrativeMemory|Events")
	FOnIntegrativeMemoryPassCompiledSignature OnIntegrativePassCompiled;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|IntegrativeMemory")
	float IntegrationClarityPercent = 100.0f;
};
