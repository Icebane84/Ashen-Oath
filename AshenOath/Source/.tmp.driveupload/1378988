// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenShadowMarkVisualStressTester.generated.h"

/**
 * UAshenShadowMarkVisualStressTester
 * Editor Subsystem stress testing rapid corruption level updates on character mesh shaders.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenShadowMarkVisualStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunShadowMarkVisualStressTest();
};
