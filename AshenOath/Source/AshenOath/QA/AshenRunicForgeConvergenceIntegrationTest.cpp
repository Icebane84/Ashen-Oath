// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Soul/AshenSoulTypes.h"
#include "Combat/AshenBladeAscensionEvaluator.h"
#include "Combat/AshenSigilResonanceEvaluator.h"
#include "Combat/AshenRunicForgeBalanceDataAsset.h"
#include "Combat/AshenRunicForgeTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

// =============================================================================
// 1. UNIT TEST: Struct Alignment & Non-Saturating Invariants
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRunicForgeUnitTest,
	"AshenOath.RunicForge.Unit.MemoryAndStructs",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenRunicForgeUnitTest::RunTest(const FString& Parameters)
{
	TestEqual(TEXT("FSoulStateVector must remain exactly 28 bytes"), (int32)sizeof(FSoulStateVector), 28);
	return true;
}

// =============================================================================
// 2. INTEGRATION TEST: Ascension Pipeline & Relational Flow Glint Gating
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRunicForgeIntegrationTest,
	"AshenOath.RunicForge.Integration.AscensionAndResonance",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenRunicForgeIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("RunicForgeTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UAshenBladeAscensionEvaluator* AscensionEval = NewObject<UAshenBladeAscensionEvaluator>(World);
	UAshenSigilResonanceEvaluator* SigilEval = NewObject<UAshenSigilResonanceEvaluator>(World);
	UAshenRunicForgeBalanceDataAsset* BalanceData = NewObject<UAshenRunicForgeBalanceDataAsset>(World);

	TestNotNull(TEXT("AscensionEval instantiated"), AscensionEval);
	TestNotNull(TEXT("SigilEval instantiated"), SigilEval);
	TestNotNull(TEXT("BalanceData instantiated"), BalanceData);

	if (AscensionEval && SigilEval && BalanceData)
	{
		FSoulStateVector SoulState;
		FRelationalMatrix_V2 RelMatrix;

		// 1. Test Tier 1 Baseline
		SoulState.Resolve = 0.50f;
		SoulState.IntegrationDebt = 0.0f;
		const EOathbringerAscensionTier Tier1 = AscensionEval->EvaluateAscensionTier(SoulState, RelMatrix, BalanceData);
		TestEqual(TEXT("Baseline must evaluate to Burdened Iron"), Tier1, EOathbringerAscensionTier::Tier1_DullNightsteel);

		// 2. Test Tier 3 via Relational Predicate
		RelMatrix.TrioResonance = 0.70f;
		RelMatrix.GarrettProfile.TacticalConfidence = 0.70f;
		RelMatrix.GarrettProfile.SomaticDread = 0.20f;
		RelMatrix.SerafinaProfile.TacticalConfidence = 0.70f;
		RelMatrix.SerafinaProfile.TransferenceBurnout = 0.30f;
		const EOathbringerAscensionTier Tier3 = AscensionEval->EvaluateAscensionTier(SoulState, RelMatrix, BalanceData);
		TestEqual(TEXT("Attuned and stable party must evaluate to Sundered Sovereign"), Tier3, EOathbringerAscensionTier::Tier3_SunderedSovereign);

		// 3. Test Flow Glint Distance Gating: Companion at 650uu MUST FAIL
		FSomaticState SomaticState;
		SomaticState.RelationalFlow = 0.85f;
		SomaticState.IsolationPressure = 0.20f;
		FHybridFinisherPayload Payload;

		const bool bGlintAt650uu = SigilEval->EvaluateHybridFinisher(
			EGuardSigilSocket::VomTag, EGuardSigilSocket::Pflug, SomaticState, 650.0f, BalanceData, Payload);
		TestFalse(TEXT("Flow Glint MUST be rejected when companion is at 650uu"), bGlintAt650uu);

		// 4. Test Flow Glint in Tight Pocket: Companion at 150uu MUST SUCCEED
		const bool bGlintAt150uu = SigilEval->EvaluateHybridFinisher(
			EGuardSigilSocket::VomTag, EGuardSigilSocket::Pflug, SomaticState, 150.0f, BalanceData, Payload);
		TestTrue(TEXT("Flow Glint MUST succeed when companion is at 150uu"), bGlintAt150uu);
		TestNearlyEqual(TEXT("Cataclysm Vortex applies 1.40x poise break multiplier"), Payload.PoiseBreakMultiplier, 1.40f, 0.01f);
	}

	World->DestroyWorld(false);
	return true;
}

// =============================================================================
// 3. ARCHITECTURAL CONTRACT TEST: Single Source of Truth Boundaries
// =============================================================================
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenRunicForgeContractTest,
	"AshenOath.RunicForge.Contract.SSoTBoundaries",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenRunicForgeContractTest::RunTest(const FString& Parameters)
{
	UStruct* SoulStruct = FSoulStateVector::StaticStruct();
	TestNotNull(TEXT("FSoulStateVector struct reflected"), SoulStruct);

	if (SoulStruct)
	{
		TestNull(TEXT("ParasitePressure must not exist in canonical FSoulStateVector"),
			SoulStruct->FindPropertyByName(FName("ParasitePressure")));
		TestNull(TEXT("InternalFriction must not exist in canonical FSoulStateVector"),
			SoulStruct->FindPropertyByName(FName("InternalFriction")));
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
