// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGASAbilityInputBindingAuditor.generated.h"

/**
 * UAshenGASAbilityInputBindingAuditor
 * Editor subsystem auditing GAS ability input bindings for imprint safety.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGASAbilityInputBindingAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Editor")
	bool AuditGASAbilityInputBindings() const;
};
