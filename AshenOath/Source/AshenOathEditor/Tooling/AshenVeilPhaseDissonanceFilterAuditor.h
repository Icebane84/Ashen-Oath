// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenVeilPhaseDissonanceFilterAuditor.generated.h"

/**
 * UAshenVeilPhaseDissonanceFilterAuditor
 * Editor Subsystem auditing veil phase dissonance filter scalars and mesh distortion parameters.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenVeilPhaseDissonanceFilterAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditVeilPhaseDissonanceFilters();
};
