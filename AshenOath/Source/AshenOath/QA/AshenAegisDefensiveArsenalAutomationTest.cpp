// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 805: Ashen Aegis Defensive Arsenal Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenAegisHalfSwordBraceComponent.h"
#include "AshenAegisCrownGuardCounterBindAbility.h"
#include "AshenDevilsBargainChillingSilenceSubsystem.h"

// =============================================================================
//  Test 1: Aegis Half Sword Brace Component — Execute Brace
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAegisHalfSwordBraceComponentTest,
	"AshenOath.AegisBrace.Component.ExecuteBrace",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAegisHalfSwordBraceComponentTest::RunTest(const FString& Parameters)
{
	UAshenAegisHalfSwordBraceComponent* BraceComp = NewObject<UAshenAegisHalfSwordBraceComponent>();
	if (!TestNotNull(TEXT("AegisHalfSwordBraceComponent must be constructable"), BraceComp)) return false;

	BraceComp->ExecuteHalfSwordBrace(200.0f);
	TestTrue(TEXT("bIsBracing must equal true"), BraceComp->bIsBracing);

	return true;
}

// =============================================================================
//  Test 2: Aegis Crown Guard Counter Bind Ability — Execute Ability
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenAegisCrownGuardCounterBindAbilityTest,
	"AshenOath.CrownGuard.Ability.ExecuteCounterBind",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenAegisCrownGuardCounterBindAbilityTest::RunTest(const FString& Parameters)
{
	UAshenAegisCrownGuardCounterBindAbility* CounterBind = NewObject<UAshenAegisCrownGuardCounterBindAbility>();
	if (!TestNotNull(TEXT("AegisCrownGuardCounterBindAbility must be constructable"), CounterBind)) return false;

	CounterBind->ExecuteCrownGuardCounterBind(nullptr, 250.0f);
	return true;
}

// =============================================================================
//  Test 3: Devil's Bargain Chilling Silence Subsystem — Evaluate Protocol
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDevilsBargainChillingSilenceSubsystemTest,
	"AshenOath.ChillingSilence.Subsystem.EvaluateProtocol",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDevilsBargainChillingSilenceSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenDevilsBargainChillingSilenceSubsystem* Subsystem = NewObject<UAshenDevilsBargainChillingSilenceSubsystem>();
	if (!TestNotNull(TEXT("DevilsBargainChillingSilenceSubsystem must be constructable"), Subsystem)) return false;

	Subsystem->EvaluateChillingSilenceProtocol(4);
	TestTrue(TEXT("bIsChillingSilenceActive must be true after 4 dark surrenders"), Subsystem->bIsChillingSilenceActive);

	return true;
}
