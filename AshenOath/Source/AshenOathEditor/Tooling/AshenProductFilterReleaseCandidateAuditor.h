// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterReleaseCandidateAuditor.generated.h"

/**
 * UAshenProductFilterReleaseCandidateAuditor
 * Gatekeeper auditing build health across all 20 vertical slice domains.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterReleaseCandidateAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditReleaseCandidateHealth();
};
