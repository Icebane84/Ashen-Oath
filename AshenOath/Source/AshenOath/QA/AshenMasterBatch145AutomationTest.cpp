// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "World/AshenDynamicRubblePhysicsSubsystem.h"
#include "World/AshenFallingMasonryHazardEvaluator.h"
#include "World/AshenRubbleMassImpulseEvaluator.h"
#include "World/AshenRubbleClearingDirectorComponent.h"
#include "Combat/AshenRubblePhysicsHapticBridge.h"
#include "Core/AshenRubblePhysicsSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch145AutomationTest,
	"AshenOath.World.MasterBatch145_EnvironmentalDestructionDynamicRubblePhysics",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch145AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST FALLING MASONRY CRUSHING DAMAGE & TELEGRAPH RADIUS
	// -----------------------------------------------------------------------------------
	{
		UAshenFallingMasonryHazardEvaluator* HazardEvaluator = NewObject<UAshenFallingMasonryHazardEvaluator>();

		// Crushing Damage = (Mass * 1.5) + (Height * 25)
		// Mass: 200kg, Height: 10m -> (300) + (250) = 550 Dmg
		const float Dmg = HazardEvaluator->EvaluateCrushingDamage(200.0f, 10.0f);
		TestNearlyEqual(TEXT("200kg falling 10m does 550 Dmg"), Dmg, 550.0f, 0.01f);

		// Telegraph Radius for 25kg -> 150uu; for 600kg -> 450uu
		TestNearlyEqual(TEXT("25kg telegraph radius is 150uu"), HazardEvaluator->EvaluateTelegraphRadius(25.0f), 150.0f, 0.01f);
		TestNearlyEqual(TEXT("600kg telegraph radius is 450uu"), HazardEvaluator->EvaluateTelegraphRadius(600.0f), 450.0f, 0.01f);
		TestNearlyEqual(TEXT("Telegraph duration is 1.2s"), HazardEvaluator->GetTelegraphWarningDurationSeconds(), 1.2f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST RUBBLE MASS IMPULSE & NAVMESH TRAVERSAL COSTS
	// -----------------------------------------------------------------------------------
	{
		UAshenRubbleMassImpulseEvaluator* ImpulseEvaluator = NewObject<UAshenRubbleMassImpulseEvaluator>();

		// Navmesh cost: Fine Gravel = 1.0x, Heavy Boulder = 4.5x
		TestNearlyEqual(TEXT("Fine Gravel navmesh cost is 1.0x"), ImpulseEvaluator->EvaluateNavmeshCostModifier(ERubbleFractureTier::FineGravel, 10.0f), 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Heavy Boulder navmesh cost is 4.5x"), ImpulseEvaluator->EvaluateNavmeshCostModifier(ERubbleFractureTier::HeavyBoulder, 300.0f), 4.5f, 0.01f);

		// Kinetic impulse: 100kg @ 10m/s -> 1000 Ns
		const float Impulse = ImpulseEvaluator->EvaluateKineticImpulseForce(100.0f, 10.0f);
		TestNearlyEqual(TEXT("Kinetic impulse is 1000 Ns"), Impulse, 1000.0f, 0.01f);

		// Choke point impassable check (>= 200kg)
		TestTrue(TEXT("250kg is impassable choke"), ImpulseEvaluator->IsChokePointImpassable(250.0f));
		TestFalse(TEXT("100kg is passable"), ImpulseEvaluator->IsChokePointImpassable(100.0f));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST THERMAL SHOCK DEMOLITION EFFICIENCY
	// -----------------------------------------------------------------------------------
	{
		UAshenRubbleClearingDirectorComponent* DemolitionDirector = NewObject<UAshenRubbleClearingDirectorComponent>();

		// Standard vs Thermal Shock Demolition
		TestNearlyEqual(TEXT("Standard demolition efficiency is 1.0x"), DemolitionDirector->EvaluateDemolitionEfficiency(false), 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Thermal shock demolition efficiency is 1.6x (+60%)"), DemolitionDirector->EvaluateDemolitionEfficiency(true), 1.6f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenRubblePhysicsHapticBridge* HapticBridge = NewObject<UAshenRubblePhysicsHapticBridge>();
		float TriggerRes = 0.0f;
		float CollapseRumble = 0.0f;
		float DemolitionPulse = 0.0f;

		// Collapse impact haptics
		HapticBridge->EvaluateRubbleHaptics(EMasonryCollapseState::CollapsingImpact, EDemolitionToolType::KaelenHeavyCleave, 450.0f, TriggerRes, CollapseRumble, DemolitionPulse);
		TestNearlyEqual(TEXT("Heavy rubble trigger resistance is 0.95"), TriggerRes, 0.95f, 0.01f);
		TestNearlyEqual(TEXT("Collapse rumble gain is 1.0"), CollapseRumble, 1.0f, 0.01f);
		TestNearlyEqual(TEXT("Demolition pulse is 0.85"), DemolitionPulse, 0.85f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenRubblePhysicsSaveGameAdapter* SaveAdapter = NewObject<UAshenRubblePhysicsSaveGameAdapter>();
		SaveAdapter->PackageRubbleState(true, true, 15.0f);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		bool bCollapsed = false;
		bool bPassageCleared = false;
		float RemainingMass = 0.0f;

		const bool bSuccess = SaveAdapter->RestoreRubbleState(bCollapsed, bPassageCleared, RemainingMass);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("Collapsed is true"), bCollapsed);
		TestTrue(TEXT("Passage cleared is true"), bPassageCleared);
		TestNearlyEqual(TEXT("Remaining mass is 15kg"), RemainingMass, 15.0f, 0.01f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
