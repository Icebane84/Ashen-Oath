// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenStateTreeTaskImprintAuditorSubsystem.generated.h"

/**
 * UAshenStateTreeTaskImprintAuditorSubsystem
 * Editor subsystem auditing StateTree tasks for imprint recording compliance.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenStateTreeTaskImprintAuditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Editor")
	bool AuditStateTreeTasks() const;
};
