// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenGarrettGrappleStressTester.generated.h"

/**
 * UAshenGarrettGrappleStressTester
 * Editor Subsystem stress testing 700uu grapple velocity and companion interposition under rapid calls.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenGarrettGrappleStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunGarrettGrappleStressTest();
};
