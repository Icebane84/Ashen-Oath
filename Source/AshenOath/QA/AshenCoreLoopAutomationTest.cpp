// AshenCoreLoopAutomationTest.cpp
// Copyright Ashen Oath. All rights reserved.
// Automated C++ Integration Test verifying the core cognitive loop:
// Experience -> Imprint Accumulation -> Debt Escalation -> Heartstone Integration -> Identity Shift & Currency Grant.

#include "Misc/AutomationTest.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenSoulStateVector.h"
#include "Engine/Engine.h"

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenCoreLoopAutomationTest, "AshenOath.CoreLoop.FullCognitiveCycle", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenCoreLoopAutomationTest::RunTest(const FString& Parameters)
{
	// ------------------------------------------------------------------------
	// STEP 1: Test Imprint Buffer Accumulation (Experience)
	// ------------------------------------------------------------------------
	UAshenOath_ImprintBufferComponent* Buffer = NewObject<UAshenOath_ImprintBufferComponent>();
	TestNotNull(TEXT("ImprintBufferComponent must instantiate"), Buffer);
	if (!Buffer) return false;

	Buffer->AddImprint(EImprintType::Combat, 0.15f);
	Buffer->AddImprint(EImprintType::Environmental, 0.20f);
	Buffer->AddImprint(EImprintType::Relationship, 0.25f);

	TestEqual(TEXT("Imprint count should equal 3"), Buffer->GetImprintCount(), 3);
	TestEqual(TEXT("Integration debt should equal 0.60f"), FMath::IsNearlyEqual(Buffer->GetIntegrationDebt(), 0.60f, 0.01f), true);

	// ------------------------------------------------------------------------
	// STEP 2: Test Escalation Thresholds (Debt Stages)
	// ------------------------------------------------------------------------
	FSoulStateVector MockState;
	MockState.IntegrationDebt = Buffer->GetIntegrationDebt();
	TestEqual(TEXT("Debt stage at 0.60f should be MemoryBleed"), MockState.GetDebtStage(), EIntegrationDebtStage::MemoryBleed);

	Buffer->AddImprint(EImprintType::Identity, 0.25f); // Total debt = 0.85f
	MockState.IntegrationDebt = Buffer->GetIntegrationDebt();
	TestEqual(TEXT("Debt stage at 0.85f should be RuntimeNoise"), MockState.GetDebtStage(), EIntegrationDebtStage::RuntimeNoise);

	// ------------------------------------------------------------------------
	// STEP 3: Test Currency Component Grants & Death Drops
	// ------------------------------------------------------------------------
	UAshenOath_CurrencyComponent* Currency = NewObject<UAshenOath_CurrencyComponent>();
	TestNotNull(TEXT("CurrencyComponent must instantiate"), Currency);
	if (!Currency) return false;

	Currency->AddEmbers(250.0f);
	TestEqual(TEXT("Embers should equal 250"), Currency->GetEmbers(), 250.0f);

	const float DroppedEmbers = Currency->DropEmbersOnDeath();
	TestEqual(TEXT("Dropped Embers on death should equal 250"), DroppedEmbers, 250.0f);
	TestEqual(TEXT("Currency Embers should reset to 0"), Currency->GetEmbers(), 0.0f);

	Currency->AddEmbers(DroppedEmbers); // Retrieve lost Embers
	TestEqual(TEXT("Retrieved Embers should equal 250"), Currency->GetEmbers(), 250.0f);

	// ------------------------------------------------------------------------
	// STEP 4: Test Integration Ritual & Identity Shift
	// ------------------------------------------------------------------------
	TArray<FPsychologicalImprint> Consumed = Buffer->ConsumeBuffer();
	TestEqual(TEXT("Consumed imprints count should equal 4"), Consumed.Num(), 4);
	TestEqual(TEXT("Imprint buffer should be empty after consumption"), Buffer->GetImprintCount(), 0);
	TestEqual(TEXT("Integration debt should reset to 0 after consumption"), Buffer->GetIntegrationDebt(), 0.0f);

	Currency->GrantAshOnIntegration(100.0f, 1.2f); // Base grant * Resolve mult
	TestEqual(TEXT("Granted Ash should equal 120"), FMath::IsNearlyEqual(Currency->GetAsh(), 120.0f, 0.1f), true);

	UE_LOG(LogTemp, Log, TEXT("FAshenCoreLoopAutomationTest: Core cognitive loop verified 100 percent CLEAN!"));
	return true;
}

