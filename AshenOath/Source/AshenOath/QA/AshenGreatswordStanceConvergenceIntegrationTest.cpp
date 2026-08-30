// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenGreatswordStanceFlowComponent.h"
#include "Combat/AshenOathbringerLifecycleComponent.h"
#include "Combat/AshenStanceFlowBalanceDataAsset.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. UNIT TEST: Liechtenauer 4-Guard Modifiers & Kinetic Routing
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenStanceFlowUnitModifiersTest,
	"AshenOath.StanceFlow.Unit.4GuardModifiers",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenStanceFlowUnitModifiersTest::RunTest(const FString& Parameters)
{
	UAshenGreatswordStanceFlowComponent* StanceComp = NewObject<UAshenGreatswordStanceFlowComponent>();
	TestNotNull(TEXT("Stance Flow component created"), StanceComp);

	if (StanceComp)
	{
		// Test 1: Vom Tag poise modifier (1.40x)
		StanceComp->TransitionToGuard(EOathbringerMartialStance::VomTag_HighWrath);
		TestEqual(TEXT("Vom Tag active guard"), StanceComp->GetCurrentStance(), EOathbringerMartialStance::VomTag_HighWrath);
		TestEqual(TEXT("Vom Tag poise multiplier is 1.40"), StanceComp->GetActivePoiseMultiplier(), 1.40f);

		// Test 2: Kinetic Routing Oberhau (Vom Tag -> Pflug) applies -30% stamina discount
		float FinalStamina = 0.0f;
		StanceComp->ExecuteKineticAttackRouting(EOathbringerMartialStance::Pflug_LowPlow, 100.0f, FinalStamina);
		TestEqual(TEXT("Oberhau follow-through Pflug stamina is 70.0"), FinalStamina, 70.0f);
		TestEqual(TEXT("Current guard transitioned to Pflug"), StanceComp->GetCurrentStance(), EOathbringerMartialStance::Pflug_LowPlow);

		// Test 3: Ochs extended parry window (0.10 + 0.12 = 0.22s)
		StanceComp->TransitionToGuard(EOathbringerMartialStance::Ochs_CrownGuard);
		TestEqual(TEXT("Ochs parry window is 0.22s"), StanceComp->GetActiveParryWindow(), 0.22f);

		// Test 4: Mordhau 100% Armor Penetration
		StanceComp->TransitionToGuard(EOathbringerMartialStance::Mordhau_HalfSword);
		TestEqual(TEXT("Mordhau armor penetration is 1.00"), StanceComp->GetActiveArmorPenetration(), 1.00f);
	}

	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TEST: Dynamic 3-Zone 115 BPM Flow Glint & Companion Pocket
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenFlowGlint3ZoneIntegrationTest,
	"AshenOath.StanceFlow.Integration.Dynamic3ZoneFlowGlint",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenFlowGlint3ZoneIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("FlowGlintTestWorld"));
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
			AActor* PlayerActor = World->SpawnActor<AActor>();
			AActor* GarrettActor = World->SpawnActor<AActor>();
			TestNotNull(TEXT("Player Actor spawned"), PlayerActor);
			TestNotNull(TEXT("Garrett Actor spawned"), GarrettActor);

			if (PlayerActor && GarrettActor)
			{
				PlayerActor->SetActorLocation(FVector(0.0f, 0.0f, 0.0f));
				GarrettActor->SetActorLocation(FVector(150.0f, 0.0f, 0.0f)); // 150uu distance (<= 200uu pocket)

				UAshenGreatswordStanceFlowComponent* StanceComp = NewObject<UAshenGreatswordStanceFlowComponent>(PlayerActor);
				TestNotNull(TEXT("Stance Component created on Player"), StanceComp);

				if (StanceComp)
				{
					// Test A: Perfect Flow Glint Window (0.10s after opening at 1.00s)
					StanceComp->TriggerFlowGlintWindow(1.00f);
					float SpeedBoost = 1.0f;
					EFlowChainingTimingQuality Quality = StanceComp->EvaluateFlowGlintInput(1.10f, SpeedBoost);

					TestEqual(TEXT("Perfect timing returns FlowGlintClean"), Quality, EFlowChainingTimingQuality::FlowGlintClean);
					TestEqual(TEXT("Speed boost is 1.25x (+25%)"), SpeedBoost, 1.25f);

					// Test B: Dual-Sigil Companion Pocket Resonance with Garrett in Vom Tag
					StanceComp->TransitionToGuard(EOathbringerMartialStance::VomTag_HighWrath);
					const bool bResonance = StanceComp->EvaluateCompanionPocketResonance(GarrettActor, FName("Garrett"));
					TestTrue(TEXT("Dual-Sigil resonance triggered with Garrett"), bResonance);

					// Assert publisher received +0.05 Garrett Trust
					const FSoulStateVector State = Publisher->GetSoulState();
					TestTrue(TEXT("Publisher received Garrett trust reward"), State.GarrettTrust > 0.0f);
				}
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

// -----------------------------------------------------------------------------
// 3. CONTRACT TEST: Oathbringer 3-Stage Weapon Lifecycle & Runic Loci Sockets
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenOathbringerLifecycleContractTest,
	"AshenOath.Oathbringer.Contract.LifecycleSSoTSync",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenOathbringerLifecycleContractTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("LifecycleContractWorld"));
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
			UAshenOathbringerLifecycleComponent* WeaponLifecycle = NewObject<UAshenOathbringerLifecycleComponent>(World);
			TestNotNull(TEXT("Weapon Lifecycle Component created"), WeaponLifecycle);

			if (WeaponLifecycle)
			{
				// Stage 1: Baseline Dormant (Resolve < 0.70, Corruption < 0.70)
				FSoulStateVector DormantState;
				DormantState.Resolve = 0.50f;
				DormantState.Corruption = 0.20f;
				Publisher->CommitStateDirect(DormantState);

				WeaponLifecycle->EvaluateWeaponLifecycle();
				TestEqual(TEXT("Dormant lifecycle state"), WeaponLifecycle->GetCurrentLifecycleState(), EOathbringerLifecycleState::Dormant);
				TestEqual(TEXT("Dormant weapon mass is 120kg"), WeaponLifecycle->GetEffectiveWeaponMass(), 120.0f);

				// Stage 2: Predictive Flow State (Resolve >= 0.70)
				FSoulStateVector FlowState;
				FlowState.Resolve = 0.85f;
				FlowState.Corruption = 0.10f;
				Publisher->CommitStateDirect(FlowState);

				WeaponLifecycle->EvaluateWeaponLifecycle();
				TestEqual(TEXT("Predictive lifecycle state"), WeaponLifecycle->GetCurrentLifecycleState(), EOathbringerLifecycleState::Predictive);
				TestEqual(TEXT("Predictive weapon mass is 45kg"), WeaponLifecycle->GetEffectiveWeaponMass(), 45.0f);

				// Stage 3: Autonomous Shadow Pull (Corruption >= 0.70)
				FSoulStateVector ShadowState;
				ShadowState.Corruption = 0.75f;
				Publisher->CommitStateDirect(ShadowState);

				WeaponLifecycle->EvaluateWeaponLifecycle();
				TestEqual(TEXT("Autonomous lifecycle state"), WeaponLifecycle->GetCurrentLifecycleState(), EOathbringerLifecycleState::Autonomous);
				TestEqual(TEXT("Autonomous weapon mass is 0kg"), WeaponLifecycle->GetEffectiveWeaponMass(), 0.0f);
				TestEqual(TEXT("Forward pull impulse is +400uu/s"), WeaponLifecycle->GetForwardPullImpulse(), 400.0f);

				// Sockets Inscription Test
				WeaponLifecycle->InscribeMemoryEchoToGuardSocket(EOathbringerMartialStance::VomTag_HighWrath, FName("Echo_RighteousCleave"));
				TestEqual(TEXT("Echo inscribed to Vom Tag socket"), WeaponLifecycle->GetSocketInscribedEcho(EOathbringerMartialStance::VomTag_HighWrath), FName("Echo_RighteousCleave"));
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
