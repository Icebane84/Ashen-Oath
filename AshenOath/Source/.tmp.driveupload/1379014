// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenMultiCharacterGASStressTester.generated.h"

/**
 * UAshenMultiCharacterGASStressTester
 * Editor Subsystem stress testing concurrent multi-actor GAS ability activations, root motion updates, and cancellation states.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenMultiCharacterGASStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunMultiCharacterGASStressTest();
};
