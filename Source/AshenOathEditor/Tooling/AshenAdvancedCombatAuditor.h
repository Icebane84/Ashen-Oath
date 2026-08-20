// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenAdvancedCombatAuditor.generated.h"

/**
 * UAshenAdvancedCombatAuditor
 * Editor Subsystem auditing frame-accurate parry windows, unchained berserk multipliers, and void shatter physics.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenAdvancedCombatAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditAdvancedCombatPipeline();
};
