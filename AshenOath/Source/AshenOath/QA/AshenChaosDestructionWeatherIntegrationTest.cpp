// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "World/AshenChaosNavMeshCutterComponent.h"
#include "World/AshenWeatherShelterThermodynamicsComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulDerivationSubsystem.h"
#include "Soul/AshenSoulStateVector.h"
#include "Soul/AshenSoulTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. UNIT TEST: Chaos Obstacle Geometry & Parabolic Vault Gating
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenChaosNavMeshUnitTest,
	"AshenOath.Chaos.Unit.ObstacleAndVaultGating",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenChaosNavMeshUnitTest::RunTest(const FString& Parameters)
{
	UAshenChaosNavMeshCutterComponent* Cutter = NewObject<UAshenChaosNavMeshCutterComponent>();
	TestNotNull(TEXT("Cutter component allocated"), Cutter);

	if (Cutter)
	{
		const FVector RubbleCenter(500.0f, 500.0f, 0.0f);
		// Register a 300uu rubble collapse with 120uu height
		Cutter->RegisterFractureRubbleCollapse(RubbleCenter, 300.0f, 120.0f);

		// Assert spatial obstacle detection
		TestTrue(TEXT("Center of rubble is obstructed"), Cutter->IsLocationObstructed(RubbleCenter));
		TestTrue(TEXT("Nearby point inside radius is obstructed"), Cutter->IsLocationObstructed(FVector(600.0f, 500.0f, 0.0f)));
		TestFalse(TEXT("Distant point is clear"), Cutter->IsLocationObstructed(FVector(1200.0f, 500.0f, 0.0f)));

		// Assert parabolic vault necessity across the rubble midpoint
		const FVector VaultStart(200.0f, 500.0f, 0.0f);
		const FVector VaultEnd(800.0f, 500.0f, 0.0f);
		TestTrue(TEXT("Vault path crossing rubble midpoint requires parabolic arc"), Cutter->RequiresParabolicVault(VaultStart, VaultEnd));
	}

	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TEST: Environmental Exposure Accrues Canonical Integration Debt
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenWeatherThermodynamicsIntegrationTest,
	"AshenOath.Weather.Integration.ExposureToIntegrationDebt",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenWeatherThermodynamicsIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("WeatherTestWorld"));
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
			// Reset publisher state
			FSoulStateVector Baseline;
			Baseline.Resolve = 0.80f;
			Baseline.Corruption = 0.0f;
			Baseline.IntegrationDebt = 0.0f;
			Baseline.Isolation = 0.0f;
			Publisher->CommitStateDirect(Baseline);

			UAshenWeatherShelterThermodynamicsComponent* Thermodynamics = NewObject<UAshenWeatherShelterThermodynamicsComponent>(World);
			TestNotNull(TEXT("Thermodynamics component created"), Thermodynamics);

			if (Thermodynamics)
			{
				// Simulate 10 seconds of Wilderness exposure (+0.02/s)
				Thermodynamics->SetShelterTier(EAshenShelterTier::Wilderness);
				Thermodynamics->TickEnvironmentalExposure(10.0f);

				const FSoulStateVector PostWildernessState = Publisher->GetSoulState();
				TestTrue(TEXT("Wilderness exposure accrues canonical Integration Debt"), PostWildernessState.IntegrationDebt >= 0.15f);

				// Transition to Haven Brazier and simulate 5 seconds of purging (-0.05/s)
				Thermodynamics->SetShelterTier(EAshenShelterTier::HavenBrazier);
				Thermodynamics->TickEnvironmentalExposure(5.0f);

				const FSoulStateVector PostHavenState = Publisher->GetSoulState();
				TestTrue(TEXT("Haven Brazier purges canonical Integration Debt"), PostHavenState.IntegrationDebt < PostWildernessState.IntegrationDebt);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
