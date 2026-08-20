// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 515: Ashen Identity Compiler & Failure Memory Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenSerafinaIdentityCompilerSubsystem.h"
#include "AshenUserWidget_CampfireInterpretiveLensMenu.h"
#include "GA_SerafinaLorekeeperInsightExecution.h"

// =============================================================================
//  Test 1: Serafina Identity Compiler Subsystem — Compile Identity
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSerafinaIdentityCompilerTest,
	"AshenOath.IdentityCompiler.Subsystem.CompileIdentity",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenSerafinaIdentityCompilerTest::RunTest(const FString& Parameters)
{
	UAshenSerafinaIdentityCompilerSubsystem* Compiler = NewObject<UAshenSerafinaIdentityCompilerSubsystem>();
	if (!TestNotNull(TEXT("SerafinaIdentityCompilerSubsystem must be constructable"), Compiler)) return false;

	const FName LensTag(TEXT("Lens.Grace"));
	bool bCompiled = Compiler->CompileIdentityForCampfireLens(LensTag);
	TestTrue(TEXT("CompileIdentityForCampfireLens must return true"), bCompiled);
	TestEqual(TEXT("ActiveInterpretiveLens must equal Lens.Grace"), Compiler->GetActiveInterpretiveLens(), LensTag);

	return true;
}

// =============================================================================
//  Test 2: Campfire Interpretive Lens Menu Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCampfireLensMenuWidgetTest,
	"AshenOath.UI.CampfireLensMenuWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCampfireLensMenuWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_CampfireInterpretiveLensMenu* Widget = NewObject<UAshenUserWidget_CampfireInterpretiveLensMenu>();
	if (!TestNotNull(TEXT("CampfireInterpretiveLensMenu widget must be constructable"), Widget)) return false;

	Widget->UpdateInterpretiveLensDisplay(FName(TEXT("Lens.Grace")), 1.0f);
	TestEqual(TEXT("DisplayedCompiledMetric must equal 1.0"), Widget->DisplayedCompiledMetric, 1.0f);

	return true;
}

// =============================================================================
//  Test 3: Serafina Lorekeeper Insight Execution — Class Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLorekeeperInsightClassTest,
	"AshenOath.GAS.SerafinaLorekeeperInsightExecution.ClassReflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenLorekeeperInsightClassTest::RunTest(const FString& Parameters)
{
	UClass* AbilityClass = FindObject<UClass>(nullptr, TEXT("/Script/AshenOath.GA_SerafinaLorekeeperInsightExecution"));
	TestNotNull(TEXT("UGA_SerafinaLorekeeperInsightExecution must be registered in UObject system"), AbilityClass);
	return true;
}
