// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGASAbilityTaskImprintAuditor.generated.h"

/**
 * UAshenGASAbilityTaskImprintAuditor
 * Subsystem auditing custom GAS AbilityTasks for imprint recording safety.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGASAbilityTaskImprintAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditGASAbilityTaskImprintSafety();
};
