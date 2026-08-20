// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone895MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone895MasterSynthesisOrchestrator
 * GameInstance subsystem auditing builds 1 to 895.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone895MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Orchestration")
	bool AuditMasterMilestone895() const;
};
