// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenOathBreachConsequenceStressTester.generated.h"

/**
 * UAshenOathBreachConsequenceStressTester
 * Editor Subsystem stress testing breach cascades (mental damage 25.0, imprint delta 0.35, emissive dimming, -50 cents pitch drop).
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenOathBreachConsequenceStressTester : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool RunBreachConsequenceStressTest();
};
