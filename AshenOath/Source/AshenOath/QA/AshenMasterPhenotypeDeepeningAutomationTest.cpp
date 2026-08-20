// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "Companions/AshenCompanionCoverSelectionPhenotypeAdapter.h"
#include "Companions/AshenSerafinaAuraResonanceVisualizerComponent.h"
#include "World/AshenSanctuaryBlessingPhenotypeModifier.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterPhenotypeDeepeningTest,
	"AshenOath.Milestone755.MasterPhenotypeDeepening.Validation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenMasterPhenotypeDeepeningTest::RunTest(const FString& Parameters)
{
	FSoulStateVector State;
	State.Resolve = 0.8f;
	State.SerafinaTrust = 0.9f;

	// 1. Test Serafina Aura Resonance
	UAshenSerafinaAuraResonanceVisualizerComponent* AuraComp = NewObject<UAshenSerafinaAuraResonanceVisualizerComponent>();
	AuraComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Serafina aura brightness matches trust"), AuraComp->GetAuraBrightness(), 2.7f);

	// 2. Test Sanctuary Blessing Potency
	UAshenSanctuaryBlessingPhenotypeModifier* BlessingComp = NewObject<UAshenSanctuaryBlessingPhenotypeModifier>();
	BlessingComp->OnSoulStateInvalidated(State);
	TestEqual(TEXT("Blessing potency scales 2x resolve"), BlessingComp->GetBlessingPotency(), 1.6f);

	return true;
}
