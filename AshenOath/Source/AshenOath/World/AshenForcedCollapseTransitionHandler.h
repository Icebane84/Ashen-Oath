// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenForcedCollapseTransitionHandler.generated.h"

/**
 * UAshenForcedCollapseTransitionHandler
 * World subsystem managing involuntary Forced Collapse transitions when IntegrationDebt >= 1.0f.
 * Auto-selects fallback Lens and forces Mindscape entry with structural handicaps.
 */
UCLASS()
class ASHENOATH_API UAshenForcedCollapseTransitionHandler : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bCollapseTransitionInProgress = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	bool TriggerInvoluntaryForcedCollapse(float DebtLevel);
};
