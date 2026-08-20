// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGASAbilityCooldownImprintAuditor.generated.h"

/**
 * UAshenGASAbilityCooldownImprintAuditor
 * Subsystem auditing GameplayAbility cooldown triggers for state tracking.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGASAbilityCooldownImprintAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditGASAbilityCooldownImprints();
};
