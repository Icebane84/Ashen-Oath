// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "World/AshenJournalHandwritingPhenotypeIntegrator.h"
#include "World/AshenDiegeticAudioDistortionPhenotypeIntegrator.h"
#include "Companions/AshenSerafinaAuraPhenotypeAdapter.h"
#include "Combat/AshenUnreliableNeedlePhenotypeIntegrator.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFullPhenotypeIntegrationTest,
	"AshenOath.Milestone735.FullPhenotype.Integration",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)

bool FAshenFullPhenotypeIntegrationTest::RunTest(const FString& Parameters)
{
	FSoulStateVector State;
	State.Resolve = 0.2f;
	State.Corruption = 0.9f;

	// 1. Test Journal Handwriting Integrator
	UAshenJournalHandwritingPhenotypeIntegrator* JournalComp = NewObject<UAshenJournalHandwritingPhenotypeIntegrator>();
	JournalComp->OnSoulStateInvalidated(State);
	TestTrue(TEXT("Journal handwriting wobble is high for low resolve"), JournalComp->GetHandwritingWobbleScalar() > 0.7f);

	// 2. Test Audio Distortion Integrator
	UAshenDiegeticAudioDistortionPhenotypeIntegrator* AudioComp = NewObject<UAshenDiegeticAudioDistortionPhenotypeIntegrator>();
	AudioComp->OnSoulStateInvalidated(State);
	TestTrue(TEXT("Audio distortion scales with corruption"), AudioComp->GetAudioDistortion() > 0.6f);

	return true;
}
