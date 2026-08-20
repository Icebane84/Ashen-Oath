// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 178: Ashen Companion Systems Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenKaelenParryCounterComponent.h"
#include "AshenGarrettTrapNetworkComponent.h"
#include "AshenSerafinaAuraFieldComponent.h"
#include "AshenDynamicMusicSubsystem.h"
#include "AshenUserWidget_CompassBar.h"

// =============================================================================
//  Test 1: Kaelen Parry Counter — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenKaelenParryReflectionTest,
	"AshenOath.Combat.KaelenParry.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenKaelenParryReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenKaelenParryCounterComponent must be valid"),
		UAshenKaelenParryCounterComponent::StaticClass() != nullptr);

	UFunction* OpenFn = UAshenKaelenParryCounterComponent::StaticClass()->FindFunctionByName(FName("OpenParryWindow"));
	TestNotNull(TEXT("OpenParryWindow must be a registered UFUNCTION"), OpenFn);

	return true;
}

// =============================================================================
//  Test 2: Garrett Trap Network — Slot Enforcement
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGarrettTrapSlotTest,
	"AshenOath.Traps.GarrettTrapNetwork.SlotEnforcement",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenGarrettTrapSlotTest::RunTest(const FString& Parameters)
{
	UAshenGarrettTrapNetworkComponent* Comp = NewObject<UAshenGarrettTrapNetworkComponent>();
	if (!TestNotNull(TEXT("TrapNetworkComponent must be constructable"), Comp)) return false;

	Comp->MaxActiveTrapSlots = 2;

	Comp->RegisterTrap(FName("Trap_A"), FVector(0.0f));
	Comp->RegisterTrap(FName("Trap_B"), FVector(100.0f));
	TestEqual(TEXT("Active trap count must be 2"), Comp->GetActiveTrapCount(), 2);

	// Third trap should be rejected
	Comp->RegisterTrap(FName("Trap_C"), FVector(200.0f));
	TestEqual(TEXT("Active trap count must still be 2 after overflow"), Comp->GetActiveTrapCount(), 2);

	// Deregister one and confirm slot freed
	Comp->DeregisterTrap(FName("Trap_A"));
	TestEqual(TEXT("Active trap count must be 1 after deregister"), Comp->GetActiveTrapCount(), 1);

	return true;
}

// =============================================================================
//  Test 3: Serafina Aura Field — Activation State
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSerafinaAuraActivationTest,
	"AshenOath.Companion.SerafinaAura.ActivationState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSerafinaAuraActivationTest::RunTest(const FString& Parameters)
{
	UAshenSerafinaAuraFieldComponent* Comp = NewObject<UAshenSerafinaAuraFieldComponent>();
	if (!TestNotNull(TEXT("AuraFieldComponent must be constructable"), Comp)) return false;

	TestFalse(TEXT("Aura must not be active on construction"), Comp->IsAuraActive());
	return true;
}

// =============================================================================
//  Test 4: Dynamic Music Subsystem — State Transition
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDynamicMusicTransitionTest,
	"AshenOath.Audio.DynamicMusic.StateTransition",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDynamicMusicTransitionTest::RunTest(const FString& Parameters)
{
	UAshenDynamicMusicSubsystem* Sub = NewObject<UAshenDynamicMusicSubsystem>();
	if (!TestNotNull(TEXT("DynamicMusicSubsystem must be constructable"), Sub)) return false;

	// Starts in Exploration
	TestEqual(TEXT("Initial state must be Exploration"),
		Sub->GetCurrentMusicState(), EAshenMusicState::Exploration);

	Sub->TransitionToState(EAshenMusicState::BossFight);
	TestEqual(TEXT("State must be BossFight after transition"),
		Sub->GetCurrentMusicState(), EAshenMusicState::BossFight);

	// Redundant transition — must stay in BossFight
	Sub->TransitionToState(EAshenMusicState::BossFight);
	TestEqual(TEXT("State must remain BossFight after redundant transition"),
		Sub->GetCurrentMusicState(), EAshenMusicState::BossFight);

	return true;
}

// =============================================================================
//  Test 5: Compass Bar Widget — Heading Normalization
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompassBarNormalizationTest,
	"AshenOath.UI.CompassBar.HeadingNormalization",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCompassBarNormalizationTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_CompassBar* Widget = NewObject<UAshenUserWidget_CompassBar>();
	if (!TestNotNull(TEXT("CompassBar widget must be constructable"), Widget)) return false;

	Widget->UpdateHeading(0.0f);
	TestEqual(TEXT("North (0 deg) must map to 0.0 scroll offset"), Widget->GetCompassScrollOffset(), 0.0f);

	Widget->UpdateHeading(180.0f);
	TestEqual(TEXT("South (180 deg) must map to 0.5 scroll offset"), Widget->GetCompassScrollOffset(), 0.5f);

	Widget->UpdateHeading(360.0f);
	TestEqual(TEXT("Full circle (360 deg) must wrap to 0.0"), Widget->GetCompassScrollOffset(), 0.0f);

	return true;
}
