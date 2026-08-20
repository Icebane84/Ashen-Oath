// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Companions/AshenCompanionMarginaliaEvaluatorComponent.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenJournalMarginaliaAutomationTest, "AshenOath.Companions.JournalMarginaliaTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenJournalMarginaliaAutomationTest::RunTest(const FString& Parameters)
{
	UAshenCompanionMarginaliaEvaluatorComponent* Evaluator = NewObject<UAshenCompanionMarginaliaEvaluatorComponent>();
	TestNotNull(TEXT("Evaluator created"), Evaluator);

	FSoulStateVector TestState;
	TestState.GarrettTrust = 0.85f;
	TestState.SerafinaTrust = 0.75f;
	Evaluator->EvaluateMarginalia(TestState);

	TestTrue(TEXT("Garrett marginalia populated"), !Evaluator->GetActiveGarrettMarginalia().IsEmpty());
	TestTrue(TEXT("Serafina marginalia populated"), !Evaluator->GetActiveSerafinaMarginalia().IsEmpty());
	return true;
}
