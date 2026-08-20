// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBlackboardKeySignatureAuditor.generated.h"

/**
 * UAshenBlackboardKeySignatureAuditor
 * Subsystem auditing Blackboard key signatures against C++ struct fields.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBlackboardKeySignatureAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditBlackboardKeySignatures();
};
