// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Soul/AshenSoulStateVector.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulDerivationSubsystem.h"
#include "Combat/AshenDeferenceComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. UNIT TESTS: Mathematical & Struct Layout Invariants
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSoulMathUnitTest,
	"AshenOath.Unit.SoulDerivationMath",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenSoulMathUnitTest::RunTest(const FString& Parameters)
{
	// Test Struct Size Invariant (28 Bytes Exact)
	TestEqual(TEXT("FSoulStateVector must be exactly 28 bytes"), (int32)sizeof(FSoulStateVector), 28);

	// Test Non-Saturating Manifold Derivation
	UAshenSoulDerivationSubsystem* DerivationEngine = NewObject<UAshenSoulDerivationSubsystem>();
	TestNotNull(TEXT("DerivationEngine created"), DerivationEngine);

	if (DerivationEngine)
	{
		FSoulStateVector TestState;
		TestState.IntegrationDebt = 0.80f;
		TestState.Isolation = 0.80f;
		TestState.Resolve = 0.20f;

		const float DerivedFriction = DerivationEngine->CalculateInternalFriction(TestState, 0.80f, 0.80f);
		TestTrue(TEXT("InternalFriction must scale smoothly below 1.0 on high stress"), DerivedFriction > 0.70f && DerivedFriction <= 0.95f);
	}

	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TESTS: Closed-Loop Deference & Somatic Response
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenDeferenceIntegrationTest,
	"AshenOath.Integration.CalculatedDeference",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenDeferenceIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("DeferenceTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	// Create test actors and publisher
	AActor* TestKaelen = World->SpawnActor<AActor>();
	TestNotNull(TEXT("TestKaelen spawned"), TestKaelen);

	UAshenDeferenceComponent* DeferenceComp = NewObject<UAshenDeferenceComponent>(TestKaelen);
	TestNotNull(TEXT("DeferenceComp created"), DeferenceComp);

	UAshenSoulPublisher* Publisher = NewObject<UAshenSoulPublisher>(World);
	TestNotNull(TEXT("Soul Publisher created"), Publisher);

	if (DeferenceComp && Publisher)
	{
		// Baseline Setup: High Hunger Crisis
		FSoulStateVector PreState;
		PreState.Corruption = 0.25f;
		PreState.IntegrationDebt = 0.25f;
		PreState.Isolation = 0.30f;
		PreState.GarrettTrust = 0.34f;
		PreState.SerafinaTrust = 0.34f;
		PreState.Resolve = 0.50f;
		Publisher->CommitStateDirect(PreState);

		const float InitialHunger = Publisher->GetCurrentSomaticState().ParasitePressure;

		// Execute Deference
		DeferenceComp->ExecuteCalculatedDeference(EDeferenceTarget::Garrett);
		TestTrue(TEXT("Deference is active"), DeferenceComp->IsDeferenceActive());

		// Deliver companion strike directly via publisher delta
		FSoulStateVector Delta;
		Delta.IntegrationDebt = -0.15f;
		Delta.Isolation       = -0.10f;
		Delta.GarrettTrust    = +0.25f;
		Delta.SerafinaTrust   = +0.25f;
		Delta.Corruption      = -0.05f;
		Delta.Resolve         = +0.10f;
		Publisher->CommitState(Delta);

		const FSomaticState PostSomatic = Publisher->GetCurrentSomaticState();
		const FSoulStateVector PostCanonical = Publisher->GetSoulState();

		// Assert Contract Invariants
		TestTrue(TEXT("IntegrationDebt must decrease"), PostCanonical.IntegrationDebt < PreState.IntegrationDebt);
		TestTrue(TEXT("GarrettTrust must increase"), PostCanonical.GarrettTrust > PreState.GarrettTrust);
		TestTrue(TEXT("ParasitePressure must decrease after strike"), PostSomatic.ParasitePressure < InitialHunger);
		TestTrue(TEXT("ParasitePressure must stabilize in Contained range [0.15, 0.35]"),
			PostSomatic.ParasitePressure >= 0.15f && PostSomatic.ParasitePressure <= 0.35f);
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 3. ARCHITECTURAL CONTRACT TESTS: Single Source of Truth Boundaries
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenArchitectureContractTest,
	"AshenOath.Contract.SingleSourceOfTruth",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenArchitectureContractTest::RunTest(const FString& Parameters)
{
	UStruct* SoulStateStruct = FSoulStateVector::StaticStruct();
	TestNotNull(TEXT("FSoulStateVector struct reflected"), SoulStateStruct);

	if (SoulStateStruct)
	{
		FProperty* HungerProp = SoulStateStruct->FindPropertyByName(FName("ParasitePressure"));
		TestNull(TEXT("ParasitePressure MUST NOT exist as a persistent field in FSoulStateVector"), HungerProp);

		FProperty* FrictionProp = SoulStateStruct->FindPropertyByName(FName("InternalFriction"));
		TestNull(TEXT("InternalFriction MUST NOT exist as a persistent field in FSoulStateVector"), FrictionProp);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
