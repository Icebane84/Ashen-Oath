// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCharacterFinisherGASAuditor.generated.h"

/**
 * UAshenCharacterFinisherGASAuditor
 * Editor Subsystem auditing socket name registries (hand_l, Staff_Thrust_Socket), motion warping speed curves, and GAS tag bindings.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCharacterFinisherGASAuditor : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool AuditCharacterFinisherGASPipeline();
};
