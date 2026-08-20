// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSoulConstellationKernelAuditor.generated.h"

/**
 * UAshenSoulConstellationKernelAuditor
 * Editor Subsystem auditing the Soul Constellation Kernel — FSoulStateVector integrity, imprint buffer state, and PublishStateVector broadcast chains.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSoulConstellationKernelAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditSoulConstellationKernel();
};
