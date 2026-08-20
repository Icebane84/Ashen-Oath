// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"
#include "AshenBatchAuthoringSubsystem.h"
#include "AshenBatchAuthoringUtilityWidget.generated.h"

/**
 * UAshenBatchAuthoringUtilityWidget
 * Editor utility backing class for 1-click Tri-Domain feature batch creation.
 */
UCLASS()
class ASHENOATHEDITOR_API UAshenBatchAuthoringUtilityWidget : public UEditorSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Tooling")
	bool TriggerBatchCreation(const FAshenTriDomainBatchPayload& Payload);
};
