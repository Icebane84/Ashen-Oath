// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMilestone935MasterSynthesisOrchestrator.generated.h"

UCLASS()
class ASHENOATH_API UAshenMilestone935MasterSynthesisOrchestrator : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Orchestration")
	bool ValidateMilestone935Synthesis();

private:
	bool bMilestone935Validated = false;
};
