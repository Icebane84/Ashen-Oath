// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenDevilsBargainAuditor.generated.h"

/**
 * UAshenDevilsBargainAuditor
 * Editor Subsystem auditing Devil's Bargain temporal dilation parameters, micro-physics freeze anchors, and crisis triggers.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenDevilsBargainAuditor : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditDevilsBargainPipeline();
};
