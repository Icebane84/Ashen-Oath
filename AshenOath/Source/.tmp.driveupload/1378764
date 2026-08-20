// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenUnchainedBerserkStressTester.generated.h"

/**
 * UAshenUnchainedBerserkStressTester
 * Editor Subsystem stress testing stamina/health drain rates and hyper-armor poise absorption during Unchained Berserk.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenUnchainedBerserkStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunUnchainedBerserkStressTest();
};
