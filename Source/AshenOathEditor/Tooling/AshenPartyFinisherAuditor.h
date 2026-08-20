// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenPartyFinisherAuditor.generated.h"

/**
 * UAshenPartyFinisherAuditor
 * Editor Subsystem auditing finisher selection matrix rules, motion warp target sockets, and montage synchronization tags.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenPartyFinisherAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditPartyFinisherPipeline();
};
