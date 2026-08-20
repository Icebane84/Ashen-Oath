// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBehaviorTreeDecoratorImprintAuditorSubsystem.generated.h"

/**
 * UAshenBehaviorTreeDecoratorImprintAuditorSubsystem
 * Subsystem auditing BT decorators for imprint state recording.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBehaviorTreeDecoratorImprintAuditorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditBTDecoratorImprintSafety();
};
