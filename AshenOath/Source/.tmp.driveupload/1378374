// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenVeilPhaseDissonanceAuditor.generated.h"

/**
 * UAshenVeilPhaseDissonanceAuditor
 * Editor Subsystem auditing veil phase mesh distortion scalars against threshold parameters.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenVeilPhaseDissonanceAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditVeilPhaseDissonanceScalars();
};
