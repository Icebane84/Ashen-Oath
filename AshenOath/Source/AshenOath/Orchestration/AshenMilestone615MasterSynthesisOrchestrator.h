// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenMilestone615MasterSynthesisOrchestrator.generated.h"

/**
 * UAshenMilestone615MasterSynthesisOrchestrator
 *
 * Master Milestone 615 Production Synthesis Orchestrator.
 * Validates Builds 596–615 across DiegeticJournalSubsystem, DiegeticFieldJournalWidget, EquipmentInspectionWidget, CampBehaviorInspectorWidget, Milestone600MasterSynthesisOrchestrator, MemoryConstellationGraphWidget, HeartstoneReflectionSanctuaryWidget, JourneyArchiveWidget, CompanionInterfaceAnnotationComponent, SomaticPresentationController, InterfaceWorldAvailabilitySubsystem, PsychologicalTranslationEngine, WeaponStoryHistoryComponent, CampfireInteractiveActor, HeartstoneSanctuaryShrineActor, FieldJournalPageController, ThreeLayersOfTruthInterpreter, and Milestone 615 Verification.
 */
UCLASS()
class ASHENOATH_API UAshenMilestone615MasterSynthesisOrchestrator : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Milestone615")
	void RunMilestone615SynthesisPass();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone615")
	int32 TotalBuildsCovered = 20;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Milestone615")
	bool bSynthesisPassComplete = false;
};
