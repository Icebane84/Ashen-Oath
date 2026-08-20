// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDevilsBargainDiegeticUIPromptSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnDiegeticPromptTriggeredSignature, bool, bIsPromptActive, float, DilationScale);

/**
 * UAshenDevilsBargainDiegeticUIPromptSubsystem
 *
 * Master subsystem managing UMB-UI-004 compliant crisis UI prompts (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenDevilsBargainDiegeticUIPromptSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|DiegeticPrompt")
	void TriggerDiegeticCrisisPrompt(bool bActivate);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|DiegeticPrompt|Events")
	FOnDiegeticPromptTriggeredSignature OnDiegeticPromptTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|DiegeticPrompt")
	bool bIsPromptActive = false;
};
