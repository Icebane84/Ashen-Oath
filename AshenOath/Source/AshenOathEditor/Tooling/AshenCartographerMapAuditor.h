// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCartographerMapAuditor.generated.h"

/**
 * UAshenCartographerMapAuditor
 * Editor Subsystem auditing cartographer map parameters, MVVM bindings, and spatial vector collections.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCartographerMapAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditCartographerMapPipeline();
};
