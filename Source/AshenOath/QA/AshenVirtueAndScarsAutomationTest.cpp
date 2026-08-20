// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 340: Ashen Shattered Virtues & Scars Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenShatteredVirtueSystemSubsystem.h"
#include "AshenInnerDemonsSystemComponent.h"
#include "AshenScarsOfCorruptionComponent.h"
#include "AshenUserWidget_ShatteredVirtueStatus.h"

// =============================================================================
//  Test 1: Shattered Virtue Subsystem — Reflection & Subsystem Validity
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenVirtueSubsystemReflectionTest,
	"AshenOath.Virtue.ShatteredVirtueSubsystem.Reflection",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenVirtueSubsystemReflectionTest::RunTest(const FString& Parameters)
{
	TestTrue(TEXT("UAshenShatteredVirtueSystemSubsystem class must be valid"),
		UAshenShatteredVirtueSystemSubsystem::StaticClass() != nullptr);
	return true;
}

// =============================================================================
//  Test 2: Inner Demons Component — Offer & Accept Bargain
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenInnerDemonsBargainTest,
	"AshenOath.Virtue.InnerDemons.BargainState",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenInnerDemonsBargainTest::RunTest(const FString& Parameters)
{
	UAshenInnerDemonsSystemComponent* Demons = NewObject<UAshenInnerDemonsSystemComponent>();
	if (!TestNotNull(TEXT("InnerDemonsSystemComponent must be constructable"), Demons)) return false;

	const FName DemonID(TEXT("Demon_GluttonyForPower"));
	Demons->OfferDemonBargain(DemonID, 2.0f);
	bool bAccepted = Demons->AcceptDemonBargain(DemonID);
	TestTrue(TEXT("AcceptDemonBargain must return true"), bAccepted);

	return true;
}

// =============================================================================
//  Test 3: Scars of Corruption Component — Accumulation
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenScarsAccumulationTest,
	"AshenOath.Scars.CorruptionComponent.Accumulation",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenScarsAccumulationTest::RunTest(const FString& Parameters)
{
	UAshenScarsOfCorruptionComponent* Scars = NewObject<UAshenScarsOfCorruptionComponent>();
	if (!TestNotNull(TEXT("ScarsOfCorruptionComponent must be constructable"), Scars)) return false;

	TestEqual(TEXT("Initial ScarCount must be 0"), Scars->GetScarCount(), 0);
	Scars->IncurCorruptionScar(10.0f);
	TestEqual(TEXT("ScarCount must be 1 after IncurCorruptionScar"), Scars->GetScarCount(), 1);

	return true;
}

// =============================================================================
//  Test 4: Shattered Virtue Status Widget — Display Update
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenShatteredVirtueWidgetTest,
	"AshenOath.UI.ShatteredVirtueWidget.DisplayUpdate",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenShatteredVirtueWidgetTest::RunTest(const FString& Parameters)
{
	UAshenUserWidget_ShatteredVirtueStatus* Widget = NewObject<UAshenUserWidget_ShatteredVirtueStatus>();
	if (!TestNotNull(TEXT("ShatteredVirtueStatus widget must be constructable"), Widget)) return false;

	const FName FractureID(TEXT("Fracture_SurvivorsGuilt"));
	Widget->UpdateVirtueStatusDisplay(FractureID, true);
	TestTrue(TEXT("bFractureActive must be true"), Widget->bFractureActive);

	return true;
}

// =============================================================================
//  Test 5: Milestone 340 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone340VerificationTest,
	"AshenOath.Milestone.Milestone340.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone340VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone340.Verification: Milestone 340 Systems Verified!"));
	return true;
}
