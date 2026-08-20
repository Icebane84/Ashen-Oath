// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatCharacter.h"
#include "Companions/AshenSerafinaCompanionCharacter.h"
#include "Companions/AshenGarrettCompanionCharacter.h"
#include "Companions/AshenTrioPartySpawnerComponent.h"

// =============================================================================
//  Trio Character Class & Component Binding Automation Test Suite
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenTrioCharacterBindingTest,
	"AshenOath.Characters.TrioBinding.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenTrioCharacterBindingTest::RunTest(const FString& Parameters)
{
	// Test 1: Kaelen Combat Character Component Verification
	AAshenCombatCharacter* Kaelen = NewObject<AAshenCombatCharacter>();
	if (!TestNotNull(TEXT("AAshenCombatCharacter must be constructable"), Kaelen)) return false;
	TestNotNull(TEXT("Kaelen must possess TrioPartySpawnerComponent"), Kaelen->GetTrioPartySpawnerComponent());

	// Test 2: Serafina Companion Character Component Verification
	AAshenSerafinaCompanionCharacter* Serafina = NewObject<AAshenSerafinaCompanionCharacter>();
	if (!TestNotNull(TEXT("AAshenSerafinaCompanionCharacter must be constructable"), Serafina)) return false;
	TestNotNull(TEXT("Serafina must possess BurnoutComponent"), Serafina->BurnoutComponent);
	TestNotNull(TEXT("Serafina must possess AuraFieldComponent"), Serafina->AuraFieldComponent);
	TestNotNull(TEXT("Serafina must possess AegisNetComponent"), Serafina->AegisNetComponent);
	TestNotNull(TEXT("Serafina must possess CatharsisComponent"), Serafina->CatharsisComponent);
	TestNotNull(TEXT("Serafina must possess SymptomComponent"), Serafina->SymptomComponent);
	TestNotNull(TEXT("Serafina must possess StainedCuffAdapter"), Serafina->StainedCuffAdapter);
	TestNotNull(TEXT("Serafina must possess WeavingAIDirector"), Serafina->WeavingAIDirector);
	TestNotNull(TEXT("Serafina must possess FormationComponent"), Serafina->FormationComponent);
	TestNotNull(TEXT("Serafina must possess TrustComponent"), Serafina->TrustComponent);

	// Test 3: Garrett Companion Character Component Verification
	AAshenGarrettCompanionCharacter* Garrett = NewObject<AAshenGarrettCompanionCharacter>();
	if (!TestNotNull(TEXT("AAshenGarrettCompanionCharacter must be constructable"), Garrett)) return false;
	TestNotNull(TEXT("Garrett must possess BurningSteelOilComponent"), Garrett->BurningSteelOilComponent);
	TestNotNull(TEXT("Garrett must possess GhostbloomFlareComponent"), Garrett->GhostbloomFlareComponent);
	TestNotNull(TEXT("Garrett must possess CaltropGridComponent"), Garrett->CaltropGridComponent);
	TestNotNull(TEXT("Garrett must possess TrapAIDirector"), Garrett->TrapAIDirector);
	TestNotNull(TEXT("Garrett must possess IgnitedCutlassAdapter"), Garrett->IgnitedCutlassAdapter);
	TestNotNull(TEXT("Garrett must possess FormationComponent"), Garrett->FormationComponent);
	TestNotNull(TEXT("Garrett must possess TrustComponent"), Garrett->TrustComponent);

	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	UE_LOG(LogTemp, Warning, TEXT("  ASHEN OATH — TRIO CHARACTER BLUEPRINT & COMPONENT BINDING VERIFIED CLEAN!"));
	UE_LOG(LogTemp, Warning, TEXT("================================================================================"));
	return true;
}
