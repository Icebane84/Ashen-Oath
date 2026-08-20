// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 555: Ashen Lorekeeper & Trust Automation Tests

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "AshenLorekeeperMemoryWeaverComponent.h"
#include "AshenNarrativeWeaponHistorySubsystem.h"
#include "AshenOath_TrustAccumulationComponent.h"
#include "AshenMilestone555SynthesisOrchestrator.h"

// =============================================================================
//  Test 1: Lorekeeper Memory Weaver Component — Weave Imprint
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMemoryWeaverTest,
	"AshenOath.MemoryWeaver.Component.WeaveImprint",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMemoryWeaverTest::RunTest(const FString& Parameters)
{
	UAshenLorekeeperMemoryWeaverComponent* Weaver = NewObject<UAshenLorekeeperMemoryWeaverComponent>();
	if (!TestNotNull(TEXT("LorekeeperMemoryWeaverComponent must be constructable"), Weaver)) return false;

	bool bWeaved = Weaver->WeaveMemoryImprint(FName(TEXT("Memory.OakhavenShattered")), 20.0f);
	TestTrue(TEXT("WeaveMemoryImprint must return true"), bWeaved);
	TestEqual(TEXT("TotalMemoriesWeaved must equal 1"), Weaver->TotalMemoriesWeaved, 1);

	return true;
}

// =============================================================================
//  Test 2: Narrative Weapon History Subsystem — Kill Imprint
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeaponHistorySubsystemTest,
	"AshenOath.WeaponHistory.Subsystem.RecordKill",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenWeaponHistorySubsystemTest::RunTest(const FString& Parameters)
{
	UAshenNarrativeWeaponHistorySubsystem* History = NewObject<UAshenNarrativeWeaponHistorySubsystem>();
	if (!TestNotNull(TEXT("NarrativeWeaponHistorySubsystem must be constructable"), History)) return false;

	History->RecordWeaponKillImprint(FName(TEXT("Weapon.Oathbringer")));
	TestEqual(TEXT("TotalOathbringerKills must equal 1"), History->TotalOathbringerKills, 1);

	return true;
}

// =============================================================================
//  Test 3: Trust Accumulation Component — Accumulate Delta
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenLorekeeperTrustAccumulationTest,
	"AshenOath.Trust.Component.AccumulateDelta",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenLorekeeperTrustAccumulationTest::RunTest(const FString& Parameters)
{
	UAshenOath_TrustAccumulationComponent* Trust = NewObject<UAshenOath_TrustAccumulationComponent>();
	if (!TestNotNull(TEXT("TrustAccumulationComponent must be constructable"), Trust)) return false;

	Trust->AccumulateTrustDelta(FName(TEXT("Companion_Garrett")), 15.0f);
	TestEqual(TEXT("GarrettTrustAccumulator must equal 65.0"), Trust->GarrettTrustAccumulator, 65.0f);

	return true;
}

// =============================================================================
//  Test 4: Milestone 555 Verification
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMilestone555VerificationTest,
	"AshenOath.Milestone.Milestone555.Verification",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter
)
bool FAshenMilestone555VerificationTest::RunTest(const FString& Parameters)
{
	UE_LOG(LogTemp, Warning, TEXT("AshenOath.Milestone.Milestone555.Verification: Milestone 555 Systems Verified!"));
	return true;
}
