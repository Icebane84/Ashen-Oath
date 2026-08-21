// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "Tactics/AshenSquadTacticalSubsystem.h"
#include "Tactics/AshenTemporalDilationEvaluatorComponent.h"
#include "Tactics/AshenCoOpComboSynchronizerComponent.h"
#include "Tactics/AshenTacticalOrderQueueComponent.h"
#include "UI/AshenUserWidget_SquadCommandWheelHUD.h"
#include "Core/AshenTacticalSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch125AutomationTest,
	"AshenOath.Tactics.MasterBatch125_SquadTactical",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch125AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST TACTICAL ORDER QUEUE (FIFO & CAPACITY LIMITS)
	// -----------------------------------------------------------------------------------
	{
		UAshenTacticalOrderQueueComponent* QueueComp = NewObject<UAshenTacticalOrderQueueComponent>();

		FSquadCommandEntry Cmd1;
		Cmd1.CommandType = ETacticalCommandType::GarrettWireSnare;
		Cmd1.TargetCompanionId = FName(TEXT("Garrett"));

		FSquadCommandEntry Cmd2;
		Cmd2.CommandType = ETacticalCommandType::SerafinaAegisShield;
		Cmd2.TargetCompanionId = FName(TEXT("Serafina"));

		TestTrue(TEXT("Enqueue Cmd1 succeeded"), QueueComp->EnqueueOrder(Cmd1));
		TestTrue(TEXT("Enqueue Cmd2 succeeded"), QueueComp->EnqueueOrder(Cmd2));
		TestEqual(TEXT("Queue count is 2"), QueueComp->GetQueueCount(), 2);

		FSquadCommandEntry OutCmd;
		TestTrue(TEXT("Dequeue next succeeded"), QueueComp->DequeueNextOrder(OutCmd));
		TestEqual(TEXT("Dequeued command is GarrettWireSnare"), OutCmd.CommandType, ETacticalCommandType::GarrettWireSnare);
		TestEqual(TEXT("Remaining queue count is 1"), QueueComp->GetQueueCount(), 1);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST TEMPORAL DILATION EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenTemporalDilationEvaluatorComponent* Evaluator = NewObject<UAshenTemporalDilationEvaluatorComponent>();

		const float RealtimeDilation = Evaluator->EvaluateTargetDilation(ETemporalDilationState::Realtime);
		TestNearlyEqual(TEXT("Realtime dilation is 1.00"), RealtimeDilation, 1.00f, 0.01f);

		const float SlowMoDilation = Evaluator->EvaluateTargetDilation(ETemporalDilationState::TacticalSlowMo);
		TestNearlyEqual(TEXT("Tactical SlowMo dilation is 0.20"), SlowMoDilation, 0.20f, 0.01f);

		const float FreezeDilation = Evaluator->EvaluateTargetDilation(ETemporalDilationState::ComboFreezeFrame);
		TestNearlyEqual(TEXT("Combo freeze dilation is 0.05"), FreezeDilation, 0.05f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST CO-OP COMBO SYNCHRONIZATION & MULTIPLIERS
	// -----------------------------------------------------------------------------------
	{
		UAshenCoOpComboSynchronizerComponent* Synchronizer = NewObject<UAshenCoOpComboSynchronizerComponent>();

		// 3 participants synchronized within 0.40s (window = 0.60s)
		const FTemporalComboExecutionState Sync3 = Synchronizer->EvaluateComboSync(3, 0.40f, 0.60f);
		TestTrue(TEXT("3-character combo is synchronized"), Sync3.bIsSynchronized);
		TestNearlyEqual(TEXT("3-character damage multiplier is 2.50x"), Sync3.DamageMultiplier, 2.50f, 0.01f);

		// 2 participants synchronized
		const FTemporalComboExecutionState Sync2 = Synchronizer->EvaluateComboSync(2, 0.30f, 0.60f);
		TestTrue(TEXT("2-character combo is synchronized"), Sync2.bIsSynchronized);
		TestNearlyEqual(TEXT("2-character damage multiplier is 1.80x"), Sync2.DamageMultiplier, 1.80f, 0.01f);

		// Out-of-window failure (0.75s > 0.60s window)
		const FTemporalComboExecutionState FailedSync = Synchronizer->EvaluateComboSync(3, 0.75f, 0.60f);
		TestFalse(TEXT("Combo missed sync window"), FailedSync.bIsSynchronized);
		TestNearlyEqual(TEXT("Failed sync damage multiplier is 1.00x"), FailedSync.DamageMultiplier, 1.00f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST TACTICAL WHEEL 8-SECTOR SELECTION MAPPING
	// -----------------------------------------------------------------------------------
	{
		UAshenUserWidget_SquadCommandWheelHUD* HUD = NewObject<UAshenUserWidget_SquadCommandWheelHUD>();

		// Angle 0 degrees -> Sector 0 (Garrett Wire Snare)
		HUD->UpdateSelectedSector(0.0f);
		TestEqual(TEXT("0 deg selects Sector 0"), HUD->GetSelectedSectorIndex(), 0);
		TestEqual(TEXT("Sector 0 command is GarrettWireSnare"), HUD->GetSelectedCommand(), ETacticalCommandType::GarrettWireSnare);

		// Angle 45 degrees -> Sector 1 (Serafina Aegis Shield)
		HUD->UpdateSelectedSector(45.0f);
		TestEqual(TEXT("45 deg selects Sector 1"), HUD->GetSelectedSectorIndex(), 1);
		TestEqual(TEXT("Sector 1 command is SerafinaAegisShield"), HUD->GetSelectedCommand(), ETacticalCommandType::SerafinaAegisShield);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST TACTICAL SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenTacticalSaveGameAdapter* SaveAdapter = NewObject<UAshenTacticalSaveGameAdapter>();

		SaveAdapter->PackageTacticalSettings(true, 0.20f, 1);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		bool bRestoredBulletTime = false;
		float RestoredDilation = 0.0f;
		int32 RestoredDefaultSector = 0;
		const bool bSuccess = SaveAdapter->RestoreTacticalSettings(bRestoredBulletTime, RestoredDilation, RestoredDefaultSector);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestTrue(TEXT("bEnableBulletTime restored"), bRestoredBulletTime);
		TestNearlyEqual(TEXT("DilationScale restored"), RestoredDilation, 0.20f, 0.01f);
		TestEqual(TEXT("DefaultSector restored"), RestoredDefaultSector, 1);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
