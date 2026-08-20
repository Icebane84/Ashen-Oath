// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenAnimMontageEventImprintValidatorSubsystem.generated.h"

/**
 * UAshenAnimMontageEventImprintValidatorSubsystem
 * Subsystem auditing AnimMontage notify events to ensure RecordImprint calls.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenAnimMontageEventImprintValidatorSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool ValidateMontageImprintEvents();
};
