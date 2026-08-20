// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "Companions/AshenMarginaliaSpatialLayoutEngine.h"
#include "Companions/AshenDeterministicMarginaliaFallbackProvider.h"
#include "Companions/AshenMarginaliaProvenanceValidator.h"
#include "UI/AshenParchmentDynamicMaterialAdapter.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch114AutomationTest,
	"AshenOath.Companions.MasterBatch114_CampfireMarginalia",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch114AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST SPATIAL SLOT COLLISION AVOIDANCE & CHARACTER BUDGET CLAMPING
	// -----------------------------------------------------------------------------------
	{
		UAshenMarginaliaSpatialLayoutEngine* LayoutEngine = NewObject<UAshenMarginaliaSpatialLayoutEngine>();

		// Test character clamping for Margin Slot (Max 90)
		const FString LongText = TEXT("This is a very long tactical note written by Garrett that exceeds ninety characters by a substantial margin and should be clamped cleanly.");
		const FString ClampedMarginText = LayoutEngine->ClampTextToSlotBudget(LongText, EMarginAnchorSlot::RightMargin_Lower);

		TestTrue(TEXT("Clamped margin text is <= 90 chars"), ClampedMarginText.Len() <= 90);
		TestTrue(TEXT("Clamped text ends with ellipsis"), ClampedMarginText.EndsWith(TEXT("...")));

		// Test collision resolution: 2 entries targeting RightMargin_Lower
		TArray<FMarginaliaEntry> CollidingEntries;

		FMarginaliaEntry Entry1;
		Entry1.EntryId = TEXT("entry_001");
		Entry1.AnchorSlot = EMarginAnchorSlot::RightMargin_Lower;
		Entry1.InscriptionText = TEXT("First note");
		CollidingEntries.Add(Entry1);

		FMarginaliaEntry Entry2;
		Entry2.EntryId = TEXT("entry_002");
		Entry2.AnchorSlot = EMarginAnchorSlot::RightMargin_Lower;
		Entry2.InscriptionText = TEXT("Second note");
		CollidingEntries.Add(Entry2);

		const TArray<FMarginaliaEntry> Resolved = LayoutEngine->ResolveSpatialCollisions(CollidingEntries);
		TestEqual(TEXT("Resolved count matches input"), Resolved.Num(), 2);
		TestTrue(TEXT("First entry keeps preferred slot"), Resolved[0].AnchorSlot == EMarginAnchorSlot::RightMargin_Lower);
		TestTrue(TEXT("Second entry is moved to another free slot"), Resolved[1].AnchorSlot != EMarginAnchorSlot::RightMargin_Lower);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST PROVENANCE AUDIT VALIDATION
	// -----------------------------------------------------------------------------------
	{
		UAshenMarginaliaProvenanceValidator* Validator = NewObject<UAshenMarginaliaProvenanceValidator>();

		TArray<FString> AuthorizedImprints;
		AuthorizedImprints.Add(TEXT("mem_sanctuary_001"));

		TArray<FMarginaliaEntry> Entries;

		FMarginaliaEntry ValidEntry;
		ValidEntry.InscriptionText = TEXT("Valid annotation");
		ValidEntry.TargetMemoryId = TEXT("mem_sanctuary_001");
		Entries.Add(ValidEntry);

		FMarginaliaEntry InvalidEntry;
		InvalidEntry.InscriptionText = TEXT("Hallucinated annotation");
		InvalidEntry.TargetMemoryId = TEXT("mem_unvisited_999");
		Entries.Add(InvalidEntry);

		TArray<FMarginaliaEntry> Validated;
		const bool bSuccess = Validator->ValidateEntries(Entries, AuthorizedImprints, Validated);

		TestTrue(TEXT("Provenance validator returns true for valid subset"), bSuccess);
		TestEqual(TEXT("Only valid entry is retained"), Validated.Num(), 1);
		TestEqual(TEXT("Retained entry matches valid target memory"), Validated[0].TargetMemoryId, FString(TEXT("mem_sanctuary_001")));
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST DETERMINISTIC MARGINALIA FALLBACK
	// -----------------------------------------------------------------------------------
	{
		UAshenDeterministicMarginaliaFallbackProvider* FallbackProvider = NewObject<UAshenDeterministicMarginaliaFallbackProvider>();

		FCanonicalSoulStateVector SoulState;
		SoulState.DominantLens = EOntologicalLens::Grace;
		SoulState.AccumulatedDysregulation = 0.20f;

		const TArray<FMarginaliaEntry> FallbackEntries = FallbackProvider->GenerateDeterministicEntries(SoulState, TEXT("mem_test_001"));
		TestEqual(TEXT("Generates annotations for Garrett and Serafina"), FallbackEntries.Num(), 2);
		TestEqual(TEXT("First author is Garrett"), FallbackEntries[0].Author, EMarginaliaAuthor::Garrett);
		TestEqual(TEXT("Second author is Serafina"), FallbackEntries[1].Author, EMarginaliaAuthor::Serafina);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DYNAMIC VERTEX JITTER MATH
	// -----------------------------------------------------------------------------------
	{
		UAshenParchmentDynamicMaterialAdapter* MaterialAdapter = NewObject<UAshenParchmentDynamicMaterialAdapter>();

		// Update with Debt = 1.0 -> Max Jitter (0.15)
		MaterialAdapter->UpdateParchmentShader(1.0f, 0.5f);
		TestNearlyEqual(TEXT("Jitter intensity reaches max at Debt 1.0"), MaterialAdapter->GetCurrentJitterIntensity(), 0.15f, 0.001f);

		// Calculate vertex offset at t = 0.0 -> Sin(0) = 0.0
		const float OffsetZero = MaterialAdapter->CalculateVertexJitterOffset(0.0f);
		TestNearlyEqual(TEXT("Offset at t=0 is 0"), OffsetZero, 0.0f, 0.001f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
