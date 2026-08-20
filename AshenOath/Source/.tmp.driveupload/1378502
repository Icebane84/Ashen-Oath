// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenCreepingParanoiaStressTester.generated.h"

/**
 * UAshenCreepingParanoiaStressTester
 * Editor Subsystem stress testing 100 simultaneous paranoia affliction ticks without frame-time degradation.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenCreepingParanoiaStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunCreepingParanoiaStressTest();
};
