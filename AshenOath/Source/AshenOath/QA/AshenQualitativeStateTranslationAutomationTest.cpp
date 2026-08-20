// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Soul/AshenQualitativeStateTranslationLibrary.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenQualitativeStateTranslationAutomationTest, "AshenOath.Soul.QualitativeStateTranslationTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenQualitativeStateTranslationAutomationTest::RunTest(const FString& Parameters)
{
	FText HighCorruptionDesc = UAshenQualitativeStateTranslationLibrary::GetQualitativeCorruptionDescription(0.85f);
	TestTrue(TEXT("High corruption translated"), HighCorruptionDesc.ToString().Contains(TEXT("Corrupted")));

	FText HighResolveDesc = UAshenQualitativeStateTranslationLibrary::GetQualitativeResolveDescription(0.90f);
	TestTrue(TEXT("High resolve translated"), HighResolveDesc.ToString().Contains(TEXT("Resolute")));
	return true;
}
