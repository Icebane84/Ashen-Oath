// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGuardedFrictionStressTester.generated.h"

/**
 * UAshenGuardedFrictionStressTester
 * Editor Subsystem stress testing pairwise trust drop to <= 0.35f and IntegrationDebt > 0.75f dynamic journal re-compilation.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGuardedFrictionStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunGuardedFrictionStressTest();
};
