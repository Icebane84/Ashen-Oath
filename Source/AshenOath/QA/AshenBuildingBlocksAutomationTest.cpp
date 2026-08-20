// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 171: Ashen Building Blocks Automation Tests (Builds 164-170)

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenEnemySpawnDirectorComponent.h"
#include "AshenRespawnSubsystem.h"
#include "AshenCombatReplayComponent.h"
#include "AshenUserWidget_StaminaBar.h"

// =============================================================================
//  Test 1: Enemy Spawn Director — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenEnemySpawnDirectorReflectionTest,
	"AshenOath.Spawning.EnemySpawnDirector.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenEnemySpawnDirectorReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenEnemySpawnDirectorComponent class must be valid"),
		UAshenEnemySpawnDirectorComponent::StaticClass() != nullptr);

	UFunction* StartFn = UAshenEnemySpawnDirectorComponent::StaticClass()->FindFunctionByName(
		FName(TEXT("StartEncounter")));
	TestNotNull(TEXT("StartEncounter must be a registered UFUNCTION"), StartFn);

	UFunction* KillFn = UAshenEnemySpawnDirectorComponent::StaticClass()->FindFunctionByName(
		FName(TEXT("RegisterEnemyKilled")));
	TestNotNull(TEXT("RegisterEnemyKilled must be a registered UFUNCTION"), KillFn);

	return true;
}

// =============================================================================
//  Test 2: Respawn Subsystem — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRespawnSubsystemReflectionTest,
	"AshenOath.Respawn.Subsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenRespawnSubsystemReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenRespawnSubsystem class must be valid"),
		UAshenRespawnSubsystem::StaticClass() != nullptr);

	UFunction* RegisterFn = UAshenRespawnSubsystem::StaticClass()->FindFunctionByName(
		FName(TEXT("RegisterSanctuaryLocation")));
	TestNotNull(TEXT("RegisterSanctuaryLocation must be a registered UFUNCTION"), RegisterFn);

	return true;
}

// =============================================================================
//  Test 3: Combat Replay Component — Rolling Buffer Logic
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCombatReplayRollingBufferTest,
	"AshenOath.Replay.CombatReplay.RollingBuffer",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCombatReplayRollingBufferTest::RunTest(const FString& Parameters)
{
	UAshenCombatReplayComponent* Comp = NewObject<UAshenCombatReplayComponent>();
	if (!TestNotNull(TEXT("CombatReplayComponent must be constructable"), Comp))
	{
		return false;
	}

	Comp->MaxLogEntries = 3;

	Comp->RecordCombatEvent(TEXT("Event A"), 50.0f);
	Comp->RecordCombatEvent(TEXT("Event B"), 75.0f);
	Comp->RecordCombatEvent(TEXT("Event C"), 100.0f);

	TestEqual(TEXT("Log must have 3 entries at capacity"), Comp->GetCombatLog().Num(), 3);

	// Adding a 4th entry should roll the oldest out
	Comp->RecordCombatEvent(TEXT("Event D"), 120.0f);
	TestEqual(TEXT("Log must still have 3 entries after overflow"), Comp->GetCombatLog().Num(), 3);
	TestEqual(TEXT("Oldest entry 'Event A' must be purged; new oldest is 'Event B'"),
		Comp->GetCombatLog()[0].EventDescription, FString(TEXT("Event B")));

	return true;
}

// =============================================================================
//  Test 4: Stamina Bar Widget — Exhaustion Pulse at Zero
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenStaminaBarExhaustionTest,
	"AshenOath.UI.StaminaBar.ExhaustionPulse",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenStaminaBarExhaustionTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_StaminaBar* Widget = NewObject<UAshenUserWidget_StaminaBar>();
	if (!TestNotNull(TEXT("StaminaBar widget must be constructable"), Widget))
	{
		return false;
	}

	Widget->UpdateStamina(100.0f, 100.0f);
	TestFalse(TEXT("Widget must not be exhausted at full stamina"), Widget->bIsExhausted);

	Widget->UpdateStamina(0.0f, 100.0f);
	TestTrue(TEXT("Widget must be exhausted when stamina hits zero"), Widget->bIsExhausted);
	TestEqual(TEXT("StaminaPercent must be 0.0 at empty"), Widget->CurrentStaminaPercent, 0.0f);

	return true;
}

// =============================================================================
//  Test 5: Holy Nova GAS — Class Registration
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHolyNovaClassRegistrationTest,
	"AshenOath.GAS.SerafinaHolyNova.ClassRegistration",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHolyNovaClassRegistrationTest::RunTest(const FString& Parameters)
{
	UClass* HolyNovaClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaHolyNova"));
	TestNotNull(TEXT("UGA_SerafinaHolyNova must be registered in the UObject system"), HolyNovaClass);
	return true;
}
