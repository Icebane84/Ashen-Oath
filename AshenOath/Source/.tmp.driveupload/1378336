// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenImprintResolutionStressTester.generated.h"

/**
 * UAshenImprintResolutionStressTester
 * Editor Subsystem stress testing 64-slot imprint buffer purification under rapid ritual execution.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenImprintResolutionStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunImprintResolutionStressTest();
};
