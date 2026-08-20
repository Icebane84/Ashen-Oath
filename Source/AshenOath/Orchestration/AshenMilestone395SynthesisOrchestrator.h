// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone395SynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone395SynthesisOrchestrator
 *
 * Master Milestone 395 Production Synthesis Orchestrator.
 * Validates Builds 381–395 across SoulRemnantsAbsorbCrafting, DynamicWorldEvents, TSCTargeting, CompanionDivergenceResolution, TacticalTargeting, UnchainedVoidShatter, GeopoliticalFactionMerchant, FactionMerchantShop, MindscapeDungeonGeneration, GarrettPoisonBladeExecution, and WeatherAudioModulation.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone395SynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone395")
	void RunMilestone395SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone395")
	int32 TotalBuildsCovered = 15;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone395")
	bool bSynthesisPassComplete = false;
};
