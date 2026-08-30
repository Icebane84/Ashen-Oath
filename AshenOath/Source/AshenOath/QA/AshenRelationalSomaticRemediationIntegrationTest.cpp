// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Companions/AshenCompanionTrustDivergenceSubsystem.h"
#include "Combat/AshenMartyrGuardCorruptionSpikeCalculator.h"
#include "Audio/AshenDiegeticCompanionTrustAudioComponent.h"
#include "Combat/AshenShadowMarkSurgeGASAbility.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. INTEGRATION TEST: Companion Divergence Risk SSoT Derivation
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCompanionDivergenceSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.CompanionDivergenceSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCompanionDivergenceSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("DivergenceSSoTTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);

	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	TestNotNull(TEXT("Transient GameInstance created"), GameInstance);

	if (GameInstance)
	{
		GameInstance->Init();
		World->SetGameInstance(GameInstance);

		UAshenSoulPublisher* Publisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		TestNotNull(TEXT("Soul Publisher acquired"), Publisher);

		if (Publisher)
		{
			// Setup high somatic dread on Garrett (0.80) and low trust (0.20)
			FRelationalMatrix_V2 Matrix;
			Matrix.GarrettProfile.SomaticDread = 0.80f;
			Matrix.GarrettProfile.InterpersonalTrust = 0.20f;
			Publisher->SetRelationalMatrix(Matrix);

			UAshenCompanionTrustDivergenceSubsystem* DivergenceSubsystem = World->GetSubsystem<UAshenCompanionTrustDivergenceSubsystem>();
			TestNotNull(TEXT("Divergence Subsystem acquired"), DivergenceSubsystem);

			if (DivergenceSubsystem)
			{
				const float GarrettRisk = DivergenceSubsystem->EvaluateCompanionDivergenceRisk(FName("Garrett"));
				// Risk = 0.80 * (1.0 - 0.20 * 0.5) = 0.80 * 0.90 = 0.72
				TestTrue(TEXT("High dread creates high divergence risk (> 0.65)"), GarrettRisk > 0.65f);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TEST: Martyr Corruption Spike SSoT Commit
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMartyrCorruptionSpikeSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.MartyrCorruptionSpikeSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMartyrCorruptionSpikeSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("MartyrCorruptionTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);

	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	TestNotNull(TEXT("Transient GameInstance created"), GameInstance);

	if (GameInstance)
	{
		GameInstance->Init();
		World->SetGameInstance(GameInstance);

		UAshenSoulPublisher* Publisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		TestNotNull(TEXT("Soul Publisher acquired"), Publisher);

		if (Publisher)
		{
			FSoulStateVector Baseline;
			Baseline.Corruption = 0.10f;
			Publisher->CommitStateDirect(Baseline);

			UAshenMartyrGuardCorruptionSpikeCalculator* Calc = NewObject<UAshenMartyrGuardCorruptionSpikeCalculator>(World);
			TestNotNull(TEXT("Martyr Spike Calculator created"), Calc);

			if (Calc)
			{
				// Intercept 800 damage -> (800 / 1000) * 0.25 = 0.20 spike
				const float Spike = Calc->CalculateMartyrCorruptionSpike(800.0f);
				TestEqual(TEXT("Calculated spike is 0.20"), Spike, 0.20f);

				// Assert publisher state received spike (0.10 + 0.20 = 0.30)
				const FSoulStateVector PostSpikeState = Publisher->GetSoulState();
				TestEqual(TEXT("Publisher corruption committed to 0.30"), PostSpikeState.Corruption, 0.30f);
				TestTrue(TEXT("Publisher received Integration Debt increment"), PostSpikeState.IntegrationDebt >= 0.10f);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 3. INTEGRATION TEST: Shadow Mark Surge SSoT Corruption Gating
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenShadowMarkSurgeSSoTIntegrationTest,
	"AshenOath.Remediation.Integration.ShadowMarkSurgeSSoT",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenShadowMarkSurgeSSoTIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("ShadowSurgeTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);

	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	TestNotNull(TEXT("Transient GameInstance created"), GameInstance);

	if (GameInstance)
	{
		GameInstance->Init();
		World->SetGameInstance(GameInstance);

		UAshenSoulPublisher* Publisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		TestNotNull(TEXT("Soul Publisher acquired"), Publisher);

		if (Publisher)
		{
			AActor* DummyActor = World->SpawnActor<AActor>();
			TestNotNull(TEXT("Dummy Instigator Actor created"), DummyActor);

			UAshenShadowMarkSurgeGASAbility* SurgeAbility = NewObject<UAshenShadowMarkSurgeGASAbility>(World);
			TestNotNull(TEXT("Shadow Mark Surge Ability created"), SurgeAbility);

			if (SurgeAbility && DummyActor)
			{
				// Test 1: Low Corruption (0.30 < 0.70) rejects surge
				FSoulStateVector LowCorrState;
				LowCorrState.Corruption = 0.30f;
				Publisher->CommitStateDirect(LowCorrState);

				TestFalse(TEXT("Surge rejected at low corruption"), SurgeAbility->UnleashShadowMarkSurge(DummyActor));

				// Test 2: High Corruption (0.75 >= 0.70) activates surge
				FSoulStateVector HighCorrState;
				HighCorrState.Corruption = 0.75f;
				Publisher->CommitStateDirect(HighCorrState);

				TestTrue(TEXT("Surge succeeds at high corruption"), SurgeAbility->UnleashShadowMarkSurge(DummyActor));
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
