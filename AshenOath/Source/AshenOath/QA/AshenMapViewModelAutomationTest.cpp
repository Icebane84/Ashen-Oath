// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "UI/AshenMapViewModel.h"
#include "Soul/AshenSoulStateVector.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenMapViewModelAutomationTest, "AshenOath.UI.MapViewModelTest", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenMapViewModelAutomationTest::RunTest(const FString& Parameters)
{
	UAshenMapViewModel* ViewModel = NewObject<UAshenMapViewModel>();
	TestNotNull(TEXT("ViewModel created"), ViewModel);

	FSoulStateVector TestState;
	TestState.Corruption = 0.8f;
	ViewModel->EvaluateSoulState(TestState, EAshenWorldviewFilter::Garrett);

	const FAshenMapRenderData& RenderData = ViewModel->GetMapRenderData();
	TestTrue(TEXT("Shadow marginalia triggered under high corruption"), RenderData.bTriggerShadowMarginalia);
	TestTrue(TEXT("Navigational sanctity maintained"), RenderData.bNavigationalSanctityMaintained);
	return true;
}
