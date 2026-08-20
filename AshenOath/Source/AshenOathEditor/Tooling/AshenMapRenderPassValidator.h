// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenMapRenderPassValidator.generated.h"

/**
 * UAshenMapRenderPassValidator
 * Editor Subsystem auditing the 4 independent map render passes (Geography, Expedition, Resonance, Worldview).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenMapRenderPassValidator : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMapRenderPasses();
};
