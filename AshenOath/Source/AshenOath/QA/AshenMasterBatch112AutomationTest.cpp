// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "Companions/AshenRelationalEcologySubsystem.h"
#include "Companions/AshenPatternContinuityComponent.h"
#include "Companions/AshenGarrettTacticalPredictabilityComponent.h"
#include "Companions/AshenSerafinaEmpathicBoundaryComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch112AutomationTest,
	"AshenOath.Ecology.MasterBatch112_FellowshipAndRepair",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch112AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST DETERMINISTIC FAITH EQUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenRelationalEcologySubsystem* Subsystem = NewObject<UAshenRelationalEcologySubsystem>();

		// Low threat (0.20), Zero repair velocity (0.0):
		// FaithThreshold = Clamp(0.50*0.20 - 0.40*0.0) = Clamp(0.10) = 0.15 (clamped to min)
		const float LowThreatThreshold = Subsystem->CalculateFaithThreshold(0.20f, 0.0f);
		TestNearlyEqual(TEXT("Low threat clamps to min 0.15"), LowThreatThreshold, 0.15f, 0.001f);

		// High threat (0.90), High repair velocity (0.80):
		// FaithThreshold = Clamp(0.50*0.90 - 0.40*0.80) = Clamp(0.45 - 0.32) = 0.13 -> 0.15
		const float RepairedCrisisThreshold = Subsystem->CalculateFaithThreshold(0.90f, 0.80f);
		TestNearlyEqual(TEXT("Repaired crisis keeps faith threshold low"), RepairedCrisisThreshold, 0.15f, 0.001f);

		// High threat (0.90), Zero repair velocity (0.0):
		// FaithThreshold = Clamp(0.50*0.90 - 0.40*0.0) = Clamp(0.45) = 0.45
		const float UnrepairedCrisisThreshold = Subsystem->CalculateFaithThreshold(0.90f, 0.0f);
		TestNearlyEqual(TEXT("Unrepaired crisis demands higher trust (0.45)"), UnrepairedCrisisThreshold, 0.45f, 0.001f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST PATTERN CONTINUITY & REPAIR MATRIX EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenPatternContinuityComponent* ContinuityComp = NewObject<UAshenPatternContinuityComponent>();

		TArray<FMemoryImprintPayload> MemoryGraph;

		// 3 consecutive sync finishers
		for (int32 i = 0; i < 3; i++)
		{
			FMemoryImprintPayload SyncImprint;
			SyncImprint.ImprintId = FGuid::NewGuid();
			SyncImprint.ImprintType = EMemoryImprintType::SyncFinisherExecuted;
			MemoryGraph.Add(SyncImprint);
		}

		FAshenRepairMatrix Matrix = ContinuityComp->EvaluateRepairHistory(FGuid::NewGuid(), MemoryGraph);
		TestEqual(TEXT("Consecutive cohesion beats match sync count"), Matrix.ConsecutiveCohesionBeats, 3);
		TestNearlyEqual(TEXT("Synarchy ratio is 1.0"), Matrix.SynarchyRatio, 1.0f, 0.001f);

		// Repair velocity = 1.0 * (3 / 10) = 0.30
		TestNearlyEqual(TEXT("Active repair velocity math"), Matrix.ActiveRepairVelocity, 0.30f, 0.001f);

		// Costly presence check: Trust = 0.50 >= FaithThreshold under Threat = 0.60
		// FaithThreshold = Clamp(0.50*0.60 - 0.40*0.30) = Clamp(0.30 - 0.12) = 0.18
		// Trust (0.50) >= 0.18 -> TRUE
		const bool bShouldExecute = ContinuityComp->ShouldExecuteCostlyPresence(0.50f, 0.60f, Matrix);
		TestTrue(TEXT("Companion accepts costly presence under positive repair velocity"), bShouldExecute);

		// Rupture event: Adds a conflict imprint
		FMemoryImprintPayload ConflictImprint;
		ConflictImprint.ImprintId = FGuid::NewGuid();
		ConflictImprint.ImprintType = EMemoryImprintType::CompanionConflict;
		MemoryGraph.Add(ConflictImprint);

		FAshenRepairMatrix RupturedMatrix = ContinuityComp->EvaluateRepairHistory(FGuid::NewGuid(), MemoryGraph);
		TestEqual(TEXT("Conflict resets consecutive cohesion beats to 0"), RupturedMatrix.ConsecutiveCohesionBeats, 0);
		TestEqual(TEXT("Rupture state transitions to ActiveRupture"), RupturedMatrix.CurrentRuptureState, ERelationalRuptureState::ActiveRupture);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST GARRETT TACTICAL SPACING & SERAFINA BOUNDARIES
	// -----------------------------------------------------------------------------------
	{
		UAshenGarrettTacticalPredictabilityComponent* GarrettComp = NewObject<UAshenGarrettTacticalPredictabilityComponent>();
		UAshenSerafinaEmpathicBoundaryComponent* SerafinaComp = NewObject<UAshenSerafinaEmpathicBoundaryComponent>();

		// Low friction (0.0), high trust (1.0), low fatigue (0.0) -> Spacing = Min (250uu)
		const float TightSpacing = GarrettComp->CalculateTargetSpacing(0.0f, 1.0f, 0.0f);
		TestNearlyEqual(TEXT("Harmonious spacing tightens to 250uu"), TightSpacing, 250.0f, 0.001f);

		// High friction (1.0), low trust (0.0), high fatigue (1.0) -> Spacing = Max (800uu)
		const float GuardedSpacing = GarrettComp->CalculateTargetSpacing(1.0f, 0.0f, 1.0f);
		TestNearlyEqual(TEXT("Alienated spacing expands to 800uu"), GuardedSpacing, 800.0f, 0.001f);

		// Serafina Transference Toll: 0.40 absorbed -> 0.40 * 0.75 = 0.30 soot
		const float ResultingSoot = SerafinaComp->ApplyTransferenceToll(0.40f);
		TestNearlyEqual(TEXT("Serafina transference soot accumulation"), ResultingSoot, 0.30f, 0.001f);

		// Crisis Sanctuary check: Kaelen friction = 0.85, Trust = 0.50, RepairVelocity = 0.35 -> TRUE
		const bool bSanctuaryTriggered = SerafinaComp->ShouldCastCrisisSanctuary(0.50f, 0.85f, 0.35f);
		TestTrue(TEXT("Serafina casts crisis sanctuary under high repair weight"), bSanctuaryTriggered);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
