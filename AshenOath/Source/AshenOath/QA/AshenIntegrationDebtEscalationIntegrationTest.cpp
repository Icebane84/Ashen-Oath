// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Memory/AshenIntegrationDebtAccumulatorSubsystem.h"
#include "Memory/AshenIntegrationDebtBalanceDataAsset.h"
#include "Memory/AshenMemoryBattleSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenIntegrationDebtEscalationIntegrationTest,
	"AshenOath.Convergence.Debt.EscalationAndMemoryBleed",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenIntegrationDebtEscalationIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("IntegrationDebtTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenIntegrationDebtAccumulatorSubsystem* DebtSubsystem = World->GetSubsystem<UAshenIntegrationDebtAccumulatorSubsystem>();
	UAshenMemoryBattleSubsystem* BattleSubsystem = World->GetSubsystem<UAshenMemoryBattleSubsystem>();

	TestNotNull(TEXT("UAshenIntegrationDebtAccumulatorSubsystem exists on World"), DebtSubsystem);
	TestNotNull(TEXT("UAshenMemoryBattleSubsystem exists on World"), BattleSubsystem);

	// -----------------------------------------------------------------------------------
	// 2. TEST 5-STAGE ESCALATION PROGRESSION & PARRY WINDOW DEGRADATION
	// -----------------------------------------------------------------------------------
	if (DebtSubsystem && BattleSubsystem)
	{
		DebtSubsystem->ClearAllDebt();

		// Stage 1: Stable (0.00)
		TestTrue(TEXT("Initial stage is Stable"), DebtSubsystem->GetCurrentStage() == EAshenIntegrationDebtStage::Stable);
		TestNearlyEqual(TEXT("Default parry window is 0.20s"), DebtSubsystem->GetEffectiveParryWindow(), 0.20f, 0.01f);

		// Stage 2: Latent Pressure (0.30)
		DebtSubsystem->AccumulateDebt(0.30f);
		TestTrue(TEXT("Stage transitioned to LatentPressure at 0.30"), DebtSubsystem->GetCurrentStage() == EAshenIntegrationDebtStage::LatentPressure);
		TestNearlyEqual(TEXT("Parry window remains 0.20s in LatentPressure"), DebtSubsystem->GetEffectiveParryWindow(), 0.20f, 0.01f);

		// Stage 3: Memory Bleed (0.60)
		DebtSubsystem->AccumulateDebt(0.30f);
		TestTrue(TEXT("Stage transitioned to MemoryBleed at 0.60"), DebtSubsystem->GetCurrentStage() == EAshenIntegrationDebtStage::MemoryBleed);
		TestNearlyEqual(TEXT("Parry window remains 0.20s in MemoryBleed"), DebtSubsystem->GetEffectiveParryWindow(), 0.20f, 0.01f);

		// Stage 4: Runtime Noise (0.80) -> Parry window degraded to 0.12s
		DebtSubsystem->AccumulateDebt(0.20f);
		TestTrue(TEXT("Stage transitioned to RuntimeNoise at 0.80"), DebtSubsystem->GetCurrentStage() == EAshenIntegrationDebtStage::RuntimeNoise);
		TestNearlyEqual(TEXT("Parry window degraded to 0.12s during RuntimeNoise"), DebtSubsystem->GetEffectiveParryWindow(), 0.12f, 0.01f);

		// -----------------------------------------------------------------------------------
		// 3. TEST IN-FIELD DEBT RELIEF (0.80 -> 0.65)
		// -----------------------------------------------------------------------------------
		DebtSubsystem->RelieveDebt(0.15f); // 0.80 - 0.15 = 0.65
		TestNearlyEqual(TEXT("Debt relieved to 0.65"), DebtSubsystem->GetIntegrationDebt(), 0.65f, 0.01f);
		TestTrue(TEXT("Stage recovered back to MemoryBleed"), DebtSubsystem->GetCurrentStage() == EAshenIntegrationDebtStage::MemoryBleed);
		TestNearlyEqual(TEXT("Parry window restored to 0.20s"), DebtSubsystem->GetEffectiveParryWindow(), 0.20f, 0.01f);

		// -----------------------------------------------------------------------------------
		// 4. TEST FORCED COLLAPSE (1.00) & FORCED MINDSCAPE INITIATION
		// -----------------------------------------------------------------------------------
		DebtSubsystem->AccumulateDebt(0.40f); // 0.65 + 0.40 = 1.00 (clamped)
		TestNearlyEqual(TEXT("Debt reached 100% (1.00)"), DebtSubsystem->GetIntegrationDebt(), 1.00f, 0.01f);
		TestTrue(TEXT("Stage transitioned to ForcedCollapse"), DebtSubsystem->GetCurrentStage() == EAshenIntegrationDebtStage::ForcedCollapse);
		TestTrue(TEXT("Forced Mindscape Memory Battle initiated"), BattleSubsystem->bIsMemoryBattleActive);

		// -----------------------------------------------------------------------------------
		// 5. TEST DATA ASSET LIVE OVERRIDE
		// -----------------------------------------------------------------------------------
		UAshenIntegrationDebtBalanceDataAsset* BalanceAsset = NewObject<UAshenIntegrationDebtBalanceDataAsset>(World);
		BalanceAsset->Penalties.DegradedParryWindowSeconds = 0.08f;
		DebtSubsystem->BalanceDataAsset = BalanceAsset;

		TestNearlyEqual(TEXT("DataAsset live override sets degraded parry to 0.08s"), DebtSubsystem->GetEffectiveParryWindow(), 0.08f, 0.01f);
	}

	// Cleanup
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
