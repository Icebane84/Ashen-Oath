// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenAnimBPBlendTreePhenotypeAuditor.generated.h"

/**
 * UAshenAnimBPBlendTreePhenotypeAuditor
 * Subsystem auditing AnimBP blend tree nodes for FSoulStateVector parameter bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenAnimBPBlendTreePhenotypeAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditAnimBPBlendTreeBindings();
};
