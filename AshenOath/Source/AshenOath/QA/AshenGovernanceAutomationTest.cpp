// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Narrative/AshenIdentityGovernanceValidator.h"
#include "Narrative/AshenIdentityGovernanceBalanceDataAsset.h"
#include "Narrative/AshenIdentityCompilerTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenGovernanceAutomationTest,
	"AshenOath.Narrative.IdentityCompiler.GovernanceVerificationMatrix",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenGovernanceAutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GOVERNANCE VALIDATOR
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("GovernanceTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UAshenIdentityGovernanceValidator* Validator = NewObject<UAshenIdentityGovernanceValidator>(World);
	TestNotNull(TEXT("Governance Engine Instantiated"), Validator);
	if (!Validator)
	{
		World->DestroyWorld(false);
		return false;
	}

	// Baseline authoritative environmental state
	FAshenIdentityCognitiveStateVector InitialState;
	InitialState.Corruption = 0.10f;
	InitialState.Resolve = 0.80f;
	InitialState.Isolation = 0.20f;
	InitialState.CompanionTrust = 0.60f;

	TArray<FString> MockImprintBuffer;
	MockImprintBuffer.Add(TEXT("mem_oakhaven_001"));
	MockImprintBuffer.Add(TEXT("mem_sunken_shrine"));

	// -----------------------------------------------------------------------------------
	// 2. SCENARIO A: VALID PAYLOAD EXECUTION
	// -----------------------------------------------------------------------------------
	const FString ValidJson = TEXT("{\"targetAxiom\": \"Corruption\", \"proposedDelta\": 0.15, \"supportingMemories\": [\"mem_oakhaven_001\"]}");
	const FAshenIdentityCognitiveStateVector PassedState = Validator->ValidateAndCompilePayload(ValidJson, MockImprintBuffer, InitialState);
	TestNearlyEqual(TEXT("Valid state delta correctly evaluated"), PassedState.Corruption, 0.25f, 0.001f);

	// -----------------------------------------------------------------------------------
	// 3. SCENARIO B: PROVENANCE AUDIT BLOCKS HALLUCINATIONS (ANTI-HALLUCINATION FIREWALL)
	// -----------------------------------------------------------------------------------
	const FString HallucinatedJson = TEXT("{\"targetAxiom\": \"Corruption\", \"proposedDelta\": 0.15, \"supportingMemories\": [\"mem_hallucinated_999\"]}");
	const FAshenIdentityCognitiveStateVector SafeState = Validator->ValidateAndCompilePayload(HallucinatedJson, MockImprintBuffer, InitialState);
	TestNearlyEqual(TEXT("Hallucinated payload rejected without mutating values"), SafeState.Corruption, 0.10f, 0.001f);

	// -----------------------------------------------------------------------------------
	// 4. SCENARIO C: DELTA HARD-CLAMPING ASSERTED
	// -----------------------------------------------------------------------------------
	const FString OverblownJson = TEXT("{\"targetAxiom\": \"Corruption\", \"proposedDelta\": 0.95, \"supportingMemories\": [\"mem_oakhaven_001\"]}");
	const FAshenIdentityCognitiveStateVector ClampedState = Validator->ValidateAndCompilePayload(OverblownJson, MockImprintBuffer, InitialState);
	TestNearlyEqual(TEXT("Delta clamped strictly to predefined maximum allowance ceiling (0.10 + 0.25)"), ClampedState.Corruption, 0.35f, 0.001f);

	// -----------------------------------------------------------------------------------
	// 5. SCENARIO D: PAYLOAD SIZE BOUNDARY VIOLATION REJECTION (>4KB)
	// -----------------------------------------------------------------------------------
	FString HugeJson = TEXT("{\"targetAxiom\": \"Corruption\", \"proposedDelta\": 0.15, \"supportingMemories\": [\"mem_oakhaven_001\"], \"padding\": \"");
	for (int32 i = 0; i < 3000; ++i)
	{
		HugeJson.Append(TEXT("XXXXXXXXXX"));
	}
	HugeJson.Append(TEXT("\"}"));

	const FAshenIdentityCognitiveStateVector HugeState = Validator->ValidateAndCompilePayload(HugeJson, MockImprintBuffer, InitialState);
	TestNearlyEqual(TEXT("Oversized payload rejected without mutating values"), HugeState.Corruption, 0.10f, 0.001f);

	// -----------------------------------------------------------------------------------
	// 6. SCENARIO E: ASYMMETRIC MEMORY DECAY MATH (TRAUMA VS BOND)
	// -----------------------------------------------------------------------------------
	TArray<FAshenImprintRecord> Imprints;
	FAshenImprintRecord TraumaRecord;
	TraumaRecord.MemoryId = TEXT("mem_trauma_01");
	TraumaRecord.Category = EImprintSalienceCategory::Trauma;
	TraumaRecord.Salience = 1.0f;
	Imprints.Add(TraumaRecord);

	FAshenImprintRecord BondRecord;
	BondRecord.MemoryId = TEXT("mem_bond_01");
	BondRecord.Category = EImprintSalienceCategory::CompanionBond;
	BondRecord.Salience = 1.0f;
	Imprints.Add(BondRecord);

	// 5 rest cycles elapsed
	Validator->ApplyMemoryDecay(Imprints, 5);

	// S_trauma = 1.0 * e^(-0.02 * 5) = e^(-0.10) ~= 0.9048
	// S_bond = 1.0 * e^(-0.08 * 5) = e^(-0.40) ~= 0.6703
	TestNearlyEqual(TEXT("Trauma salience decays slowly (approx 0.9048)"), Imprints[0].Salience, 0.9048f, 0.02f);
	TestNearlyEqual(TEXT("Companion bond salience decays faster (approx 0.6703)"), Imprints[1].Salience, 0.6703f, 0.02f);
	TestTrue(TEXT("Trauma is significantly more persistent than bond"), Imprints[0].Salience > Imprints[1].Salience);

	// -----------------------------------------------------------------------------------
	// 7. SCENARIO F: DATA ASSET LIVE OVERRIDE
	// -----------------------------------------------------------------------------------
	UAshenIdentityGovernanceBalanceDataAsset* BalanceAsset = NewObject<UAshenIdentityGovernanceBalanceDataAsset>(World);
	BalanceAsset->GovernanceLimits.MaxAllowableDelta = 0.40f;
	Validator->BalanceDataAsset = BalanceAsset;

	const FAshenIdentityCognitiveStateVector CustomClampedState = Validator->ValidateAndCompilePayload(OverblownJson, MockImprintBuffer, InitialState);
	TestNearlyEqual(TEXT("DataAsset live override sets clamp limit to 0.40 (0.10 + 0.40 = 0.50)"), CustomClampedState.Corruption, 0.50f, 0.001f);

	// Cleanup
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
