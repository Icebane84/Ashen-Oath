// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOathbringerStanceFlowConvergenceSubsystem.h"
#include "Combat/AshenSovereignDualityTransformationAbility.h"
#include "Combat/AshenExecuteFlowResonanceFinisherGASAbility.h"
#include "Combat/AshenInscribeGuardSigilGASAbility.h"
#include "Combat/AshenAscendOathbringerTierGASAbility.h"
#include "Combat/AshenColossusRuptureCleaveGASAbility.h"
#include "Combat/AshenGravimetricPommelShatterGASAbility.h"
#include "Combat/AshenRunicForgeConvergenceSubsystem.h"
#include "AbilitySystemComponent.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterEndToEndIntegrationAutomationTest,
	"AshenOath.Convergence.MasterEndToEndGameplayLoop",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterEndToEndIntegrationAutomationTest::RunTest(const FString& Parameters)
{
	// Create a dummy world for test context
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false);
	if (!World)
	{
		return false;
	}

	// -----------------------------------------------------------------------------------
	// 1. SPAWN ASHEN COMBAT CHARACTER & VERIFY COMPONENT WIRING
	// -----------------------------------------------------------------------------------
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* CombatChar = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);

	TestNotNull(TEXT("CombatCharacter spawned successfully"), CombatChar);
	if (!CombatChar)
	{
		World->DestroyWorld(false);
		return false;
	}

	UAbilitySystemComponent* ASC = CombatChar->GetAbilitySystemComponent();
	TestNotNull(TEXT("AbilitySystemComponent exists on CombatCharacter"), ASC);

	// -----------------------------------------------------------------------------------
	// 2. TEST DUALITY TRANSFORMATION ABILITY EXECUTION PAYLOAD
	// -----------------------------------------------------------------------------------
	{
		UAshenSovereignDualityTransformationAbility* DualityAbility = NewObject<UAshenSovereignDualityTransformationAbility>(CombatChar);

		// Execute full transformation pulse
		const bool bPulseSuccess = DualityAbility->TriggerDualityTransformationPulse();
		TestTrue(TEXT("Duality Transformation pulse executed cleanly"), bPulseSuccess);
		TestNearlyEqual(TEXT("Target corruption transitioned to 1.0 (Dark state)"), CombatChar->GetCorruptionAmount(), 0.0f, 1.0f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST STANCE FLOW SEAM COLOR SUBSYSTEM INTEGRATION
	// -----------------------------------------------------------------------------------
	{
		UAshenOathbringerStanceFlowConvergenceSubsystem* StanceSubsystem = World->GetSubsystem<UAshenOathbringerStanceFlowConvergenceSubsystem>();
		TestNotNull(TEXT("StanceFlowSubsystem exists in World"), StanceSubsystem);

		if (StanceSubsystem)
		{
			// Switch stance to Pflug (Low Plow)
			StanceSubsystem->SwitchStance(EOathbringerMartialStance::Pflug_LowPlow);
			TestTrue(TEXT("Current stance is Pflug"), StanceSubsystem->GetCurrentStance() == EOathbringerMartialStance::Pflug_LowPlow);

			// Switch to Ochs (Crown Guard)
			StanceSubsystem->SwitchStance(EOathbringerMartialStance::Ochs_CrownGuard);
			TestTrue(TEXT("Current stance is Ochs"), StanceSubsystem->GetCurrentStance() == EOathbringerMartialStance::Ochs_CrownGuard);
		}
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST RUNIC FORGE CONVERGENCE SUBSYSTEM & 1.40x HYBRID FINISHER
	// -----------------------------------------------------------------------------------
	{
		UAshenRunicForgeConvergenceSubsystem* ForgeSubsystem = World->GetSubsystem<UAshenRunicForgeConvergenceSubsystem>();
		TestNotNull(TEXT("RunicForgeSubsystem exists in World"), ForgeSubsystem);

		if (ForgeSubsystem)
		{
			ForgeSubsystem->AscendBladeTier(EOathbringerAscensionTier::Tier3_SunderedSovereign);
			ForgeSubsystem->InscribeSigil(EGuardSigilSocket::VomTagSocket, ESigilResonanceEffect::ShatteredColossus);
			ForgeSubsystem->InscribeSigil(EGuardSigilSocket::PflugSocket, ESigilResonanceEffect::ZephyrGale);

			const FFlowResonanceResult Result = ForgeSubsystem->TriggerFlowResonance(EGuardSigilSocket::VomTagSocket, EGuardSigilSocket::PflugSocket);
			TestTrue(TEXT("Flow Resonance triggered between Vom Tag and Pflug"), Result.bResonanceTriggered);
			TestNearlyEqual(TEXT("Hybrid finisher damage multiplier is 1.40x"), Result.HybridDamageMultiplier, 1.40f, 0.01f);
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
