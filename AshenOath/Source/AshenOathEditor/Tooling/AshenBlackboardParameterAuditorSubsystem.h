// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBlackboardParameterAuditorSubsystem.generated.h"

/**
 * UAshenBlackboardParameterAuditorSubsystem
 * Auditor verifying MPC & MetaSound parameter bindings against active C++ structs.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBlackboardParameterAuditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditBlackboardBindings();
};
