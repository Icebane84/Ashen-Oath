// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxStateVectorDiffEngine.generated.h"

/**
 * UAshenRICSandboxStateVectorDiffEngine
 * Engine calculating deltas between volatile imprint buffers and compiled FSoulStateVector.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxStateVectorDiffEngine : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	float CalculateStateDelta(float VolatileWeight, float CompiledState);
};
