// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 1730: Null Zone & Corruption Core Systems QA Automation Test Suite
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Orchestration/AshenMilestone1730SynthesisOrchestrator.h"
#include "World/AshenWhisperingWindSubsystem.h"
#include "World/AshenNullZoneVolume.h"
#include "World/AshenMemoryFragmentActor.h"
#include "World/AshenEnvironmentalAnchorComponent.h"
#include "Combat/AshenNullZoneGASAbility.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone1730NullZoneAutomationTest,
	"AshenOath.QA.NullZone.Milestone1730Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone1730NullZoneAutomationTest::RunTest(const FString& Parameters)
{
	// Test 1: Whispering Wind Subsystem
	UAshenWhisperingWindSubsystem* WhisperSubsystem = NewObject<UAshenWhisperingWindSubsystem>();
	if (!TestNotNull(TEXT("WhisperingWindSubsystem must be constructable"), WhisperSubsystem)) return false;
	WhisperSubsystem->UpdateWhisperIntensity(0.8f, 0.6f);
	TestEqual(TEXT("Whisper intensity must equal 0.70f"), WhisperSubsystem->CurrentWhisperIntensity, 0.70f);

	// Test 2: Null Zone Volume Proximity
	AAshenNullZoneVolume* Volume = NewObject<AAshenNullZoneVolume>();
	if (!TestNotNull(TEXT("NullZoneVolume must be constructable"), Volume)) return false;
	TestEqual(TEXT("Drain rate must equal 0.05f"), Volume->DrainRatePerSecond, 0.05f);

	// Test 3: Memory Fragment Actor
	AAshenMemoryFragmentActor* Fragment = NewObject<AAshenMemoryFragmentActor>();
	if (!TestNotNull(TEXT("MemoryFragmentActor must be constructable"), Fragment)) return false;
	TestTrue(TEXT("Unconsumed fragment must allow interaction"), Fragment->InteractWithFragment(nullptr, 0.8f));

	// Test 4: Environmental Anchor
	UAshenEnvironmentalAnchorComponent* AnchorComp = NewObject<UAshenEnvironmentalAnchorComponent>();
	if (!TestNotNull(TEXT("EnvironmentalAnchorComponent must be constructable"), AnchorComp)) return false;
	TestTrue(TEXT("ConsecrateAnchor must return true"), AnchorComp->ConsecrateAnchor());

	// Test 5: Null Zone GAS Ability
	UAshenNullZoneGASAbility* Ability = NewObject<UAshenNullZoneGASAbility>();
	if (!TestNotNull(TEXT("NullZoneGASAbility must be constructable"), Ability)) return false;
	TestEqual(TEXT("BasePurgeDamage must equal 450.0f"), Ability->BasePurgeDamage, 450.0f);

	UAshenMilestone1730SynthesisOrchestrator* Orchestrator = NewObject<UAshenMilestone1730SynthesisOrchestrator>();
	if (!TestNotNull(TEXT("Milestone 1730 Orchestrator must be constructable"), Orchestrator)) return false;
	TestTrue(TEXT("Milestone 1730 validation must return true"), Orchestrator->ValidateMilestone1730Synthesis());

	UE_LOG(LogTemp, Warning, TEXT("====== ASHEN OATH — MILESTONE 1730 NULL ZONE SUITE VERIFIED ======"));
	return true;
}
