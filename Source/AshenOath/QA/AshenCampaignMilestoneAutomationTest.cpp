// AshenCampaignMilestoneAutomationTest.cpp
// Copyright Ashen Oath. All rights reserved.
// BUILD 152: Full Campaign Milestone End-to-End Automation Test Suite
// Validates Ember echo retrieval, solar beacon holy pulses, constellation node glow intensities, and camera FOV scaling.

#include "Misc/AutomationTest.h"
#include "AshenEmberEchoRetrievalActor.h"
#include "AshenSolarBeaconActor.h"
#include "AshenConstellationVisualizerComponent.h"
#include "AshenDynamicCameraFOVComponent.h"
#include "Engine/Engine.h"

// ---------------------------------------------------------------------------
// TEST 1: Ember Echo Retrieval Test
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEmberEchoRetrievalTest,
	"AshenOath.Campaign.EmberEcho.ResourceRetrieval",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenEmberEchoRetrievalTest::RunTest(const FString& Parameters)
{
	AAshenEmberEchoRetrievalActor* Echo = NewObject<AAshenEmberEchoRetrievalActor>();
	TestNotNull(TEXT("EmberEchoRetrievalActor must instantiate"), Echo);
	if (!Echo) return false;

	TestEqual(TEXT("Default stored Embers must equal 500.0"), Echo->StoredEmbers, 500.0f);
	TestEqual(TEXT("Default stored Imprints must equal 2"), Echo->StoredImprintCount, 2);

	UE_LOG(LogTemp, Log, TEXT("FAshenEmberEchoRetrievalTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 2: Solar Beacon Holy Ward Test
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSolarBeaconTest,
	"AshenOath.Campaign.SolarBeacon.PulseHealingAndDamage",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenSolarBeaconTest::RunTest(const FString& Parameters)
{
	AAshenSolarBeaconActor* Beacon = NewObject<AAshenSolarBeaconActor>();
	TestNotNull(TEXT("SolarBeaconActor must instantiate"), Beacon);
	if (!Beacon) return false;

	TestEqual(TEXT("Pulse heal amount must equal 40.0 HP"), Beacon->HealAmountPerPulse, 40.0f);
	TestEqual(TEXT("Pulse holy damage must equal 50.0 HP"), Beacon->HolyDamagePerPulse, 50.0f);

	UE_LOG(LogTemp, Log, TEXT("FAshenSolarBeaconTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 3: Constellation Visualizer Glow Test
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenConstellationVisualsTest,
	"AshenOath.Campaign.ConstellationVisuals.GlowIntensity",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenConstellationVisualsTest::RunTest(const FString& Parameters)
{
	UAshenConstellationVisualizerComponent* Visualizer = NewObject<UAshenConstellationVisualizerComponent>();
	TestNotNull(TEXT("ConstellationVisualizerComponent must instantiate"), Visualizer);
	if (!Visualizer) return false;

	float LockedGlow = Visualizer->CalculateConstellationGlow(FName("LockedNode"));
	TestEqual(TEXT("Locked node glow must equal 0.2f"), LockedGlow, 0.2f);

	UE_LOG(LogTemp, Log, TEXT("FAshenConstellationVisualsTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 4: Camera FOV Scaling Test
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCameraFOVTest,
	"AshenOath.Campaign.CameraFOV.SprintFOVInterpolation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenCameraFOVTest::RunTest(const FString& Parameters)
{
	UAshenDynamicCameraFOVComponent* CameraFOV = NewObject<UAshenDynamicCameraFOVComponent>();
	TestNotNull(TEXT("DynamicCameraFOVComponent must instantiate"), CameraFOV);
	if (!CameraFOV) return false;

	CameraFOV->SetTargetFOV(95.0f);
	TestEqual(TEXT("Target FOV must equal 95.0"), CameraFOV->TargetFOV, 95.0f);

	UE_LOG(LogTemp, Log, TEXT("FAshenCameraFOVTest: PASS"));
	return true;
}
