// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "World/AshenTacticalMapTypes.h"
#include "World/AshenTacticalMapWaypointSubsystem.h"
#include "World/AshenFogOfWarCartographyEvaluator.h"
#include "World/AshenTravelHazardAmbushEvaluator.h"
#include "World/AshenSanctuaryFastTravelDirectorComponent.h"
#include "Combat/AshenTacticalMapHapticBridge.h"
#include "Core/AshenTacticalMapSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch147AutomationTest,
	"AshenOath.World.MasterBatch147_TacticalMapFastTravelSanctuaryWaypoint",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch147AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST FOG OF WAR UNVEIL RADIUS & LOOKOUT VANTAGE
	// -----------------------------------------------------------------------------------
	{
		UAshenFogOfWarCartographyEvaluator* FogEvaluator = NewObject<UAshenFogOfWarCartographyEvaluator>();

		// Base radius: 800uu
		TestNearlyEqual(TEXT("Base fog radius without torch is 800uu"), FogEvaluator->EvaluateFogUnveilRadius(0.0f, false, false), 800.0f, 0.01f);

		// Torch bonus: +400uu -> 1200uu
		TestNearlyEqual(TEXT("Torch lit fog radius is 1200uu"), FogEvaluator->EvaluateFogUnveilRadius(0.0f, true, false), 1200.0f, 0.01f);

		// Lookout vantage point: 3500uu
		TestNearlyEqual(TEXT("Lookout vantage reveal is 3500uu"), FogEvaluator->EvaluateFogUnveilRadius(0.0f, false, true), 3500.0f, 0.01f);

		// Unveil query check
		TestTrue(TEXT("Point within 500uu is unveiled"), FogEvaluator->IsLocationUnveiled(FVector::ZeroVector, 1000.0f, FVector(500.0f, 0.0f, 0.0f)));
		TestFalse(TEXT("Point outside 1500uu is veiled"), FogEvaluator->IsLocationUnveiled(FVector::ZeroVector, 1000.0f, FVector(1500.0f, 0.0f, 0.0f)));
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST TRAVEL AMBUSH RISK & EMBER-SALT PROVISIONS
	// -----------------------------------------------------------------------------------
	{
		UAshenTravelHazardAmbushEvaluator* HazardEvaluator = NewObject<UAshenTravelHazardAmbushEvaluator>();

		// 10km travel with 0.50 corruption: (10 * 3) + (0.50 * 40) = 30 + 20 = 50%
		const float AmbushRisk = HazardEvaluator->EvaluateAmbushProbability(10.0f, 0.50f, false);
		TestNearlyEqual(TEXT("10km at 50% corruption risk is 50%"), AmbushRisk, 50.0f, 0.01f);

		// Salted provisions halve risk to 25%
		const float SaltedRisk = HazardEvaluator->EvaluateAmbushProbability(10.0f, 0.50f, true);
		TestNearlyEqual(TEXT("Salted provisions reduce risk to 25%"), SaltedRisk, 25.0f, 0.01f);

		// Surprise penalty
		TestNearlyEqual(TEXT("Surprise posture penalty is 0.85x"), HazardEvaluator->EvaluateSurprisePosturePenalty(true), 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Safe posture multiplier is 1.00x"), HazardEvaluator->EvaluateSurprisePosturePenalty(false), 1.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST FAST TRAVEL STAMINA & CHANNEL DURATION
	// -----------------------------------------------------------------------------------
	{
		UAshenSanctuaryFastTravelDirectorComponent* TravelDirector = NewObject<UAshenSanctuaryFastTravelDirectorComponent>();

		// 5km travel: 5 * 15 = 75 stamina
		TestNearlyEqual(TEXT("5km travel costs 75 stamina"), TravelDirector->EvaluateFastTravelStaminaCost(5.0f), 75.0f, 0.01f);
		TestNearlyEqual(TEXT("Fast travel channel time is 3.0s"), TravelDirector->GetFastTravelChannelDurationSeconds(), 3.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS
	// -----------------------------------------------------------------------------------
	{
		UAshenTacticalMapHapticBridge* HapticBridge = NewObject<UAshenTacticalMapHapticBridge>();
		float TriggerRes = 0.0f;
		float BeaconGain = 0.0f;
		float TeleportSnap = 0.0f;

		// Map open hovering attuned sanctuary
		HapticBridge->EvaluateMapHaptics(true, 1.0f, EWaypointBeaconState::AttunedSanctuary, TriggerRes, BeaconGain, TeleportSnap);
		TestNearlyEqual(TEXT("Boundary resistance at edge is 0.85"), TriggerRes, 0.85f, 0.01f);
		TestNearlyEqual(TEXT("Attuned beacon pulse gain is 0.75"), BeaconGain, 0.75f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenTacticalMapSaveGameAdapter* SaveAdapter = NewObject<UAshenTacticalMapSaveGameAdapter>();
		SaveAdapter->PackageMapState(TEXT("Waypoint_Caldera_03"), 8, 5);
		TestTrue(TEXT("SaveData is true"), SaveAdapter->HasSavedData());

		FString RestoredSanctuary = TEXT("");
		int32 RestoredDiscovered = 0;
		int32 RestoredAttuned = 0;

		const bool bSuccess = SaveAdapter->RestoreMapState(RestoredSanctuary, RestoredDiscovered, RestoredAttuned);
		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("Restored sanctuary is Caldera"), RestoredSanctuary, TEXT("Waypoint_Caldera_03"));
		TestEqual(TEXT("Restored discovered count is 8"), RestoredDiscovered, 8);
		TestEqual(TEXT("Restored attuned count is 5"), RestoredAttuned, 5);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
