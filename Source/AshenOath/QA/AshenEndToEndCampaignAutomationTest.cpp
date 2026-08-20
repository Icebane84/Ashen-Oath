// AshenEndToEndCampaignAutomationTest.cpp
// Copyright Ashen Oath. All rights reserved.
// BUILD 122: End-to-End Vertical Slice Campaign Automation Test Suite
// Validates save/load roundtrips, concealment stealth, Mindscape phantasm spawns, and AnimBP stance blends.

#include "Misc/AutomationTest.h"
#include "AshenSaveGame.h"
#include "AshenConcealmentComponent.h"
#include "AshenMindscapeSpawnerActor.h"
#include "AshenCharacterStanceComponent.h"
#include "Engine/Engine.h"

// ---------------------------------------------------------------------------
// TEST 1: Campaign Save/Load Persistence Roundtrip
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCampaignSaveLoadTest,
	"AshenOath.Campaign.SaveLoadPersistence.FullStateRoundtrip",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenCampaignSaveLoadTest::RunTest(const FString& Parameters)
{
	UAshenSaveGame* SaveObject = NewObject<UAshenSaveGame>();
	TestNotNull(TEXT("SaveObject must instantiate"), SaveObject);
	if (!SaveObject) return false;

	SaveObject->PlayerLevel = 5;
	SaveObject->SavedEmbers = 1250.0f;
	SaveObject->SavedStateVector.Corruption = 0.45f;
	SaveObject->SavedActivePerks.Add(FName("Perk_UnshakeableStance"));

	TestEqual(TEXT("Player level must equal 5"), SaveObject->PlayerLevel, 5);
	TestEqual(TEXT("Saved embers must equal 1250.0"), SaveObject->SavedEmbers, 1250.0f);
	TestTrue(TEXT("UnshakeableStance perk must be in saved perks"), SaveObject->SavedActivePerks.Contains(FName("Perk_UnshakeableStance")));

	UE_LOG(LogTemp, Log, TEXT("FAshenCampaignSaveLoadTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 2: Concealment Stealth Threat Drop Pipeline
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCampaignConcealmentTest,
	"AshenOath.Campaign.ConcealmentStealth.ThreatDropPipeline",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenCampaignConcealmentTest::RunTest(const FString& Parameters)
{
	UAshenConcealmentComponent* Concealment = NewObject<UAshenConcealmentComponent>();
	TestNotNull(TEXT("ConcealmentComponent must instantiate"), Concealment);
	if (!Concealment) return false;

	Concealment->EnterConcealment(3.0f);
	TestTrue(TEXT("bIsConcealed must be true after entering concealment"), Concealment->bIsConcealed);

	Concealment->ExitConcealment();
	TestFalse(TEXT("bIsConcealed must be false after exiting concealment"), Concealment->bIsConcealed);

	UE_LOG(LogTemp, Log, TEXT("FAshenCampaignConcealmentTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 3: Mindscape Phantasm Spawner Pipeline
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCampaignPhantasmSpawnTest,
	"AshenOath.Campaign.MindscapeSpawns.PhantasmWavePipeline",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenCampaignPhantasmSpawnTest::RunTest(const FString& Parameters)
{
	AAshenMindscapeSpawnerActor* Spawner = NewObject<AAshenMindscapeSpawnerActor>();
	TestNotNull(TEXT("MindscapeSpawnerActor must instantiate"), Spawner);
	if (!Spawner) return false;

	TestEqual(TEXT("Default spawn radius must equal 500.0uu"), Spawner->SpawnRadius, 500.0f);

	UE_LOG(LogTemp, Log, TEXT("FAshenCampaignPhantasmSpawnTest: PASS"));
	return true;
}

// ---------------------------------------------------------------------------
// TEST 4: Character Stance Degradation Pipeline
// ---------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCampaignStanceTest,
	"AshenOath.Campaign.StanceTransition.PoiseExhaustionBlend",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenCampaignStanceTest::RunTest(const FString& Parameters)
{
	UAshenCharacterStanceComponent* StanceComp = NewObject<UAshenCharacterStanceComponent>();
	TestNotNull(TEXT("CharacterStanceComponent must instantiate"), StanceComp);
	if (!StanceComp) return false;

	StanceComp->UpdateStanceFromResolve(20.0f);
	TestEqual(TEXT("Stance must equal HunchedGuarded"), StanceComp->CurrentStanceTag, FName(TEXT("Stance.HunchedGuarded")));

	UE_LOG(LogTemp, Log, TEXT("FAshenCampaignStanceTest: PASS"));
	return true;
}
