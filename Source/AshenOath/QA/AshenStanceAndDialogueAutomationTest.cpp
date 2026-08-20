// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 545: Ashen Stance, Interception & Dialogue Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenCharacterStanceComponent.h"
#include "AshenCompanionInterceptionComponent.h"
#include "AshenDialogueSubsystem.h"

// =============================================================================
//  Test 1: Character Stance Component — Resolve Stance Blend
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCharacterStanceTest,
	"AshenOath.Stance.Component.UpdateStanceFromResolve",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCharacterStanceTest::RunTest(const FString& Parameters)
{
	UAshenCharacterStanceComponent* Stance = NewObject<UAshenCharacterStanceComponent>();
	if (!TestNotNull(TEXT("CharacterStanceComponent must be constructable"), Stance)) return false;

	Stance->UpdateStanceFromResolve(20.0f); // Low resolve -> HunchedGuarded
	TestEqual(TEXT("CurrentStanceTag must equal Stance.HunchedGuarded"), Stance->CurrentStanceTag, FName(TEXT("Stance.HunchedGuarded")));

	return true;
}

// =============================================================================
//  Test 2: Companion Interception Component — Preemptive Interception
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompanionInterceptionTest,
	"AshenOath.Interception.Component.TriggerInterception",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCompanionInterceptionTest::RunTest(const FString& Parameters)
{
	UAshenCompanionInterceptionComponent* Intercept = NewObject<UAshenCompanionInterceptionComponent>();
	if (!TestNotNull(TEXT("CompanionInterceptionComponent must be constructable"), Intercept)) return false;

	bool bTriggered = Intercept->TriggerPreemptiveInterception(FName(TEXT("Companion_Garrett")), FVector(0, 0, 0));
	TestTrue(TEXT("bInterceptionActive must equal true"), Intercept->bInterceptionActive);

	return true;
}

// =============================================================================
//  Test 3: Dialogue Subsystem — Bark Muting Check
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDialogueSubsystemTest,
	"AshenOath.Dialogue.Subsystem.BarkMuting",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenDialogueSubsystemTest::RunTest(const FString& Parameters)
{
	UAshenDialogueSubsystem* Dialogue = NewObject<UAshenDialogueSubsystem>();
	if (!TestNotNull(TEXT("DialogueSubsystem must be constructable"), Dialogue)) return false;

	Dialogue->SetBarksMuted(true);
	bool bSpoken = Dialogue->TriggerDialogueLine(FName(TEXT("Companion_Garrett")), TEXT("Behind you!"), true);
	TestFalse(TEXT("Bark must be muted when barks muted is true"), bSpoken);

	return true;
}
