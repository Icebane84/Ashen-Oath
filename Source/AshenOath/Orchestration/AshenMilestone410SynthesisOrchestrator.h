// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone410SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone410SynthesisOrchestrator
 *
 * Milestone 410 Production Synthesis Orchestrator.
 * Validates Builds 401–406 across DynamicEncounterScaler, SpatialAudioOcclusion, MemoryThreadSanctuary, CompanionComboFinisher, and MemoryThread UI.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone410SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone410")
	void RunMilestone410SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone410")
	int32 TotalBuildsCovered = 6;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone410")
	bool bSynthesisPassComplete = false;
};
