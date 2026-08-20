// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSomaticIdentityEchoAuditor.generated.h"

/**
 * UAshenSomaticIdentityEchoAuditor
 * Editor Subsystem auditing somatic identity echo scalars and psychological resonance field parameters.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSomaticIdentityEchoAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditSomaticIdentityEchoes();
};
