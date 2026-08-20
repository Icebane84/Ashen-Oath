// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenParryWindowValidator.generated.h"

/**
 * UAshenParryWindowValidator
 * Editor Subsystem validating 0.15s micro-frame parry window bounds and slow-mo time dilation clamp (0.2x).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenParryWindowValidator : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateParryWindowParameters();
};
