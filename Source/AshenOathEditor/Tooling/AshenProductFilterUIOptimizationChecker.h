// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenProductFilterUIOptimizationChecker.generated.h"

UCLASS()
class ASHENOATHEDITOR_API UAshenProductFilterUIOptimizationChecker : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Tooling")
	bool ValidateUIRenderPerformance();

private:
	float RecordedSlateFrameTimeMs = 16.6f;
};
