// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenSympatheticDamageStressTester.generated.h"

/**
 * UAshenSympatheticDamageStressTester
 * Editor Subsystem stress testing Guilt-Stitcher damage reflection loops and suture severance callbacks.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenSympatheticDamageStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunSympatheticDamageStressTest();
};
