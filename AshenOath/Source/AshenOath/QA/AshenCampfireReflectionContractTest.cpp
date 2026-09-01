// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Memory/AshenCampfireReflectionSubsystem.h"
#include "Memory/AshenCampfireTypes.h"
#include "Combat/AshenOathbringerMorphComponent.h"
#include "Combat/AshenOathbringerMetallurgyTypes.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. AUTOMATION TEST: Campfire Integration Debt Payoff to Zero
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCampfireDebtPayoffTest,
	"AshenOath.Campfire.DebtPayoff",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCampfireDebtPayoffTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("CampfireDebtWorld"));
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

		UAshenSoulPublisher* SoulPublisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		UAshenCampfireReflectionSubsystem* CampfireSubsystem = GameInstance->GetSubsystem<UAshenCampfireReflectionSubsystem>();

		TestNotNull(TEXT("Soul Publisher acquired"), SoulPublisher);
		TestNotNull(TEXT("Campfire Subsystem acquired"), CampfireSubsystem);

		if (SoulPublisher && CampfireSubsystem)
		{
			// Seed initial state with heavy Integration Debt
			FSoulStateVector SeededState;
			SeededState.Resolve = 0.40f;
			SeededState.Corruption = 0.10f;
			SeededState.IntegrationDebt = 0.75f; // Heavy trauma debt
			SoulPublisher->CommitStateDirect(SeededState);

			TestEqual(TEXT("Initial debt is 0.75"), SoulPublisher->GetSoulState().IntegrationDebt, 0.75f);

			// Queue a memory fragment
			FCampfireMemoryFragment Frag;
			Frag.MemoryID = FName("Mem_OldBridgeAmbush");
			Frag.RawTraumaWeight = 0.30f;
			CampfireSubsystem->QueueMemoryFragment(Frag);

			// Integrate through Accountability Lens
			const FCampfireIntegrationResult Result = CampfireSubsystem->IntegrateBufferedMemories(EInterpretiveLens::Accountability);

			// Assert Zero-Debt Invariant
			const FSoulStateVector PostState = SoulPublisher->GetSoulState();
			TestEqual(TEXT("Integration debt must be completely cleared to 0.0"), PostState.IntegrationDebt, 0.0f);
			TestTrue(TEXT("Resolve must increase via Accountability"), PostState.Resolve > 0.40f);
			TestTrue(TEXT("DebtCleared in result matches 0.75"), FMath::IsNearlyEqual(Result.DebtCleared, 0.75f, 0.001f));
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 2. AUTOMATION TEST: Campfire 4-Lens Routing Integrity
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCampfireLensRoutingTest,
	"AshenOath.Campfire.LensRouting",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCampfireLensRoutingTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("CampfireLensWorld"));
	TestNotNull(TEXT("Transient World created"), World);

	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	if (GameInstance)
	{
		GameInstance->Init();
		World->SetGameInstance(GameInstance);

		UAshenSoulPublisher* SoulPublisher = GameInstance->GetSubsystem<UAshenSoulPublisher>();
		UAshenCampfireReflectionSubsystem* CampfireSubsystem = GameInstance->GetSubsystem<UAshenCampfireReflectionSubsystem>();

		if (SoulPublisher && CampfireSubsystem)
		{
			// Test Nihilism / Spite lens routing
			FSoulStateVector SeededState;
			SeededState.Resolve = 0.50f;
			SeededState.Corruption = 0.20f;
			SeededState.IntegrationDebt = 0.50f;
			SoulPublisher->CommitStateDirect(SeededState);

			const FCampfireIntegrationResult NihilismResult = CampfireSubsystem->IntegrateBufferedMemories(EInterpretiveLens::Nihilism);
			const FSoulStateVector NihilismState = SoulPublisher->GetSoulState();

			TestTrue(TEXT("Nihilism must spike Corruption"), NihilismState.Corruption > 0.20f);
			TestEqual(TEXT("Nihilism must clear debt to 0.0"), NihilismState.IntegrationDebt, 0.0f);

			// Test Compassion / Grace lens routing
			SeededState.IntegrationDebt = 0.40f;
			SeededState.GarrettTrust = 0.40f;
			SeededState.SerafinaTrust = 0.40f;
			SoulPublisher->CommitStateDirect(SeededState);

			const FCampfireIntegrationResult CompassionResult = CampfireSubsystem->IntegrateBufferedMemories(EInterpretiveLens::Grace);
			const FSoulStateVector CompassionState = SoulPublisher->GetSoulState();

			TestTrue(TEXT("Compassion must increase Garrett trust"), CompassionState.GarrettTrust > 0.40f);
			TestTrue(TEXT("Compassion must increase Serafina trust"), CompassionState.SerafinaTrust > 0.40f);
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 3. AUTOMATION TEST: Oathbringer Metallurgy Morph Actuator
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenOathbringerMorphActuatorTest,
	"AshenOath.Metallurgy.MorphActuator",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenOathbringerMorphActuatorTest::RunTest(const FString& Parameters)
{
	UAshenOathbringerMorphComponent* MorphComp = NewObject<UAshenOathbringerMorphComponent>();
	TestNotNull(TEXT("Morph component instantiated"), MorphComp);

	if (MorphComp)
	{
		// 1. Test Tier 3 (The Scribed Vow - High Resolve)
		MorphComp->ApplyMetallurgyMorph(EOathbringerMetallurgicalTier::ScribedVow, 0.75f, 0.0f, 0.0f);
		TestEqual(TEXT("Tier set to Tier 3"), MorphComp->GetCurrentTier(), EOathbringerMetallurgicalTier::ScribedVow);
		TestEqual(TEXT("Air hiss frequency is 528 Hz"), MorphComp->GetCurrentAcousticProfile().AirHissFrequency, 528.0f);
		TestEqual(TEXT("Zero arcade neon emissive"), MorphComp->GetCurrentMaterialParameters().EmissiveIntensity, 0.0f);

		// 2. Test Tier 4 (Devouring Nightsteel - High Corruption)
		MorphComp->ApplyMetallurgyMorph(EOathbringerMetallurgicalTier::DevouringNightsteel, 0.20f, 0.80f, 0.0f);
		TestEqual(TEXT("Tier set to Tier 4"), MorphComp->GetCurrentTier(), EOathbringerMetallurgicalTier::DevouringNightsteel);
		TestEqual(TEXT("Light absorption radius is 2.0 inches"), MorphComp->GetCurrentMaterialParameters().LightAbsorptionRadius, 2.0f);
		TestEqual(TEXT("Tapetum Lucidum retroreflection is 1.0"), MorphComp->GetCurrentMaterialParameters().TapetumLucidumRetroreflection, 1.0f);

		// 3. Test Tier 5 (Cold Monolith - Dead Swing Silence)
		MorphComp->ApplyMetallurgyMorph(EOathbringerMetallurgicalTier::ColdMonolith, 0.95f, 0.0f, 0.0f);
		TestTrue(TEXT("Tier 5 dead acoustic isolation is active"), MorphComp->GetCurrentAcousticProfile().bDeadAcousticIsolation);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
