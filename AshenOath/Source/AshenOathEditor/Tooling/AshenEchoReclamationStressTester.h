// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenEchoReclamationStressTester.generated.h"

/**
 * UAshenEchoReclamationStressTester
 * Editor Subsystem stress testing memory fragment collection and Mindscape arena resets.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenEchoReclamationStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunEchoReclamationStressTest();
};
