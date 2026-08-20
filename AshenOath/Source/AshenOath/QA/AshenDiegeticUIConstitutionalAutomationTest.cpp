// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 605: Ashen Diegetic UI Constitutional Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenUserWidget_MemoryConstellationGraph.h"
#include "AshenUserWidget_HeartstoneReflectionSanctuary.h"
#include "AshenCompanionInterfaceAnnotationComponent.h"

// =============================================================================
//  Test 1: Memory Constellation Graph Widget — Star Types
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMemoryConstellationWidgetTest,
	"AshenOath.UI.MemoryConstellationGraph.StarTypes",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMemoryConstellationWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_MemoryConstellationGraph* GraphUI = NewObject<UAshenUserWidget_MemoryConstellationGraph>();
	if (!TestNotNull(TEXT("MemoryConstellationGraph widget must be constructable"), GraphUI)) return false;

	GraphUI->InspectMemoryStar(FName(TEXT("Memory.SunderingOath")), EAshenMemoryStarType::GoldenIntegrated, TEXT("Serafina noted Kaelen accepted the burden."));
	TestEqual(TEXT("ActiveStarType must equal GoldenIntegrated"), GraphUI->ActiveStarType, EAshenMemoryStarType::GoldenIntegrated);

	return true;
}

// =============================================================================
//  Test 2: Heartstone Reflection Sanctuary Widget — Reflection
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenHeartstoneReflectionWidgetTest,
	"AshenOath.UI.HeartstoneReflectionSanctuary.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenHeartstoneReflectionWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_HeartstoneReflectionSanctuary* ShrineUI = NewObject<UAshenUserWidget_HeartstoneReflectionSanctuary>();
	if (!TestNotNull(TEXT("HeartstoneReflectionSanctuary widget must be constructable"), ShrineUI)) return false;

	ShrineUI->ReflectAtHeartstoneSanctuary(FName(TEXT("Archetype.OathboundWarden")), 85.0f);
	TestEqual(TEXT("ActiveIntegrationProgressPercent must equal 85.0"), ShrineUI->ActiveIntegrationProgressPercent, 85.0f);

	return true;
}

// =============================================================================
//  Test 3: Companion Interface Annotation Component — Add Annotation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompanionInterfaceAnnotationTest,
	"AshenOath.CompanionAnnotation.Component.AddAnnotation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenCompanionInterfaceAnnotationTest::RunTest(const FString& Parameters)
{
	UAshenCompanionInterfaceAnnotationComponent* AnnotComp = NewObject<UAshenCompanionInterfaceAnnotationComponent>();
	if (!TestNotNull(TEXT("CompanionInterfaceAnnotationComponent must be constructable"), AnnotComp)) return false;

	AnnotComp->AddJournalAnnotation(FName(TEXT("Companion.Garrett")), FName(TEXT("Annotation.TrapDiagram")), TEXT("Garrett drew a tripwire schematic in the margin."));
	TestEqual(TEXT("TotalAnnotationsCount must equal 1"), AnnotComp->TotalAnnotationsCount, 1);

	return true;
}
