// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenRICSandboxFirewallStressTester.generated.h"

/**
 * UAshenRICSandboxFirewallStressTester
 * Stress tester validating zero-hallucination firewall limits under rapid imprint spikes.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenRICSandboxFirewallStressTester : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool StressTestFirewallLimits();
};
