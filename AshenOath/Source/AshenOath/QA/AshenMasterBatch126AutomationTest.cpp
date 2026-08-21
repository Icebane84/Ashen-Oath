// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Archive/AshenCodexArchiveTypes.h"
#include "Archive/AshenCodexArchiveSubsystem.h"
#include "Archive/AshenRelicInspectionEvaluatorComponent.h"
#include "Archive/AshenCodexMarginaliaEvaluatorComponent.h"
#include "Audio/AshenCodexAudioSubsystem.h"
#include "Core/AshenCodexSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch126AutomationTest,
	"AshenOath.Archive.MasterBatch126_CodexRepository",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch126AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST CODEX ENTRY UNLOCKING
	// -----------------------------------------------------------------------------------
	{
		UAshenCodexArchiveSubsystem* ArchiveSubsystem = NewObject<UAshenCodexArchiveSubsystem>();

		const FName TitanEntry = FName(TEXT("Lore_Titan_Nightsteel"));
		const bool bUnlocked = ArchiveSubsystem->UnlockCodexEntry(
			TitanEntry,
			ECodexCategory::BossAnatomy,
			FText::FromString(TEXT("Nightsteel Titan Anatomy")),
			FText::FromString(TEXT("Titan infused with deep corruption.")));

		TestTrue(TEXT("UnlockCodexEntry returned true"), bUnlocked);
		TestTrue(TEXT("IsEntryUnlocked is true"), ArchiveSubsystem->IsEntryUnlocked(TitanEntry));
		TestEqual(TEXT("Unlocked count is 1"), ArchiveSubsystem->GetUnlockedCount(), 1);

		// Duplicate unlock should fail gracefully
		const bool bDuplicate = ArchiveSubsystem->UnlockCodexEntry(
			TitanEntry,
			ECodexCategory::BossAnatomy,
			FText::FromString(TEXT("Nightsteel Titan Anatomy")),
			FText::FromString(TEXT("Duplicate.")));
		TestFalse(TEXT("Duplicate unlock returned false"), bDuplicate);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST RELIC 3D ANGLE ALIGNMENT & DECODED PROGRESS
	// -----------------------------------------------------------------------------------
	{
		UAshenRelicInspectionEvaluatorComponent* Evaluator = NewObject<UAshenRelicInspectionEvaluatorComponent>();

		// Secret inscription at Yaw = 180 degrees (Tolerance = 15 degrees)
		const bool bAligned = Evaluator->EvaluateSecretAngleAlignment(185.0f, 180.0f, 15.0f);
		TestTrue(TEXT("Angle 185 aligns with 180 (tolerance 15)"), bAligned);

		const bool bNotAligned = Evaluator->EvaluateSecretAngleAlignment(120.0f, 180.0f, 15.0f);
		TestFalse(TEXT("Angle 120 does not align with 180"), bNotAligned);

		// Dwell time: 2.5s / 5.0s = 50%
		const float Decoded = Evaluator->EvaluateDecodedPercentage(2.5f, 5.0f);
		TestNearlyEqual(TEXT("Decoded percent is 0.50"), Decoded, 0.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST COMPANION MARGINALIA EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenCodexMarginaliaEvaluatorComponent* MarginaliaComp = NewObject<UAshenCodexMarginaliaEvaluatorComponent>();

		// Garrett high trust (>= 0.60)
		const FText GarrettHighTrust = MarginaliaComp->EvaluateMarginaliaText(
			FName(TEXT("Lore_Titan_Nightsteel")),
			FName(TEXT("Garrett")),
			0.85f);
		TestTrue(TEXT("Garrett high trust note references tension wires"), GarrettHighTrust.ToString().Contains(TEXT("tension wires")));

		// Serafina high trust
		const FText SerafinaNote = MarginaliaComp->EvaluateMarginaliaText(
			FName(TEXT("Relic_Pyre_Censer")),
			FName(TEXT("Serafina")),
			0.75f);
		TestTrue(TEXT("Serafina note references White Flame"), SerafinaNote.ToString().Contains(TEXT("White Flame")));
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST SOLFEGGIO AUDIO RESONANCE FREQUENCIES
	// -----------------------------------------------------------------------------------
	{
		UAshenCodexAudioSubsystem* AudioSubsystem = NewObject<UAshenCodexAudioSubsystem>();

		const float RarePitch = AudioSubsystem->EvaluateRelicHumPitchHz(ERelicRarityTier::RareArtifact);
		TestNearlyEqual(TEXT("Rare artifact pitch is 528 Hz (Solfeggio Love/Repair)"), RarePitch, 528.0f, 0.01f);

		const float SacredPitch = AudioSubsystem->EvaluateRelicHumPitchHz(ERelicRarityTier::SacredHeirloom);
		TestNearlyEqual(TEXT("Sacred heirloom pitch is 741 Hz (Solfeggio Intuition)"), SacredPitch, 741.0f, 0.01f);

		const float TitanPitch = AudioSubsystem->EvaluateRelicHumPitchHz(ERelicRarityTier::TitanCoreRelic);
		TestNearlyEqual(TEXT("Titan core pitch is 852 Hz (Solfeggio Spiritual Order)"), TitanPitch, 852.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST CODEX SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenCodexSaveGameAdapter* SaveAdapter = NewObject<UAshenCodexSaveGameAdapter>();

		TArray<FName> LoreList;
		LoreList.Add(FName(TEXT("Lore_Titan_Nightsteel")));
		LoreList.Add(FName(TEXT("Relic_Pyre_Censer")));

		SaveAdapter->PackageCodexState(LoreList.Num(), LoreList);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		int32 RestoredCount = 0;
		TArray<FName> RestoredList;
		const bool bSuccess = SaveAdapter->RestoreCodexState(RestoredCount, RestoredList);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestEqual(TEXT("RestoredCount is 2"), RestoredCount, 2);
		TestEqual(TEXT("First restored lore is Lore_Titan_Nightsteel"), RestoredList[0], FName(TEXT("Lore_Titan_Nightsteel")));
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
