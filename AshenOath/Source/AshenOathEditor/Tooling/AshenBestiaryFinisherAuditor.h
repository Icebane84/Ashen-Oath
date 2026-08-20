// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBestiaryFinisherAuditor.generated.h"

/**
 * UAshenBestiaryFinisherAuditor
 * Editor Subsystem auditing tag bindings, weakspot collision sockets, and archetype override tables across all 18 finishers.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBestiaryFinisherAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditBestiaryFinisherPipeline();
};
