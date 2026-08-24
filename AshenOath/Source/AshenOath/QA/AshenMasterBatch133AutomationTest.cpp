// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "Soul/AshenTraumaSomaticsSubsystem.h"
#include "Soul/AshenProceduralVeinCorruptionEvaluator.h"
#include "Combat/AshenWeaponSootAccumulationComponent.h"
#include "Soul/AshenBioAcousticHeartbeatEvaluator.h"
#include "Audio/AshenBioAcousticAudioSubsystem.h"
#include "Scenarios/AshenTraumaSomaticsHapticBridge.h"
#include "Core/AshenTraumaSomaticsSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch133AutomationTest,
	"AshenOath.Soul.MasterBatch133_TraumaSomaticsAndWeaponSoot",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch133AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST PROCEDURAL VEIN CORRUPTION & SCLERA RED-OUT EVALUATOR
	// -----------------------------------------------------------------------------------
	{
		UAshenProceduralVeinCorruptionEvaluator* VeinEvaluator = NewObject<UAshenProceduralVeinCorruptionEvaluator>();

		// Low Debt (0.10) & Burnout (0.00) -> VeinCorruption = 0.115
		const float LowVeins = VeinEvaluator->ComputeVeinCorruption(0.10f, 0.0f);
		TestNearlyEqual(TEXT("Low debt vein corruption is ~0.115"), LowVeins, 0.115f, 0.01f);

		// High Debt (0.80) & Burnout (0.20) -> VeinCorruption = 0.80*1.15 + 0.20*0.35 = 0.92 + 0.07 = 0.99
		const float HighVeins = VeinEvaluator->ComputeVeinCorruption(0.80f, 0.20f);
		TestNearlyEqual(TEXT("High debt vein corruption is ~0.99"), HighVeins, 0.99f, 0.01f);

		// Sclera Redness (Debt 0.65 -> (0.65 - 0.30)/0.70 = 0.35/0.70 = 0.50)
		const float Sclera = VeinEvaluator->ComputeScleraRedness(0.65f);
		TestNearlyEqual(TEXT("Sclera redness is 0.50"), Sclera, 0.50f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST WEAPON SOOT ACCUMULATION FROM KINETIC ENERGY
	// -----------------------------------------------------------------------------------
	{
		UAshenWeaponSootAccumulationComponent* SootComp = NewObject<UAshenWeaponSootAccumulationComponent>();

		// Baseline clean
		TestEqual(TEXT("Baseline soot is 0.0"), SootComp->GetBladeSootScalar(), 0.0f);
		TestEqual(TEXT("Baseline nicks is 0"), SootComp->GetMicroNickCount(), 0);

		// 3 Strikes of 3000 Joules each -> 9000 Joules, Soot = (3000/5000)*0.05 * 3 = 0.03 * 3 = 0.09
		SootComp->RecordStrikeEnergy(3000.0f);
		SootComp->RecordStrikeEnergy(3000.0f);
		SootComp->RecordStrikeEnergy(3000.0f);

		TestNearlyEqual(TEXT("Accumulated soot is 0.09"), SootComp->GetBladeSootScalar(), 0.09f, 0.01f);
		TestEqual(TEXT("Micro nick count is 3"), SootComp->GetMicroNickCount(), 3);

		// Clean blade
		SootComp->CleanBlade();
		TestEqual(TEXT("Cleaned blade soot is 0.0"), SootComp->GetBladeSootScalar(), 0.0f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST BIO-ACOUSTIC HEARTBEAT & ACOUSTIC FILTER EVALUATION
	// -----------------------------------------------------------------------------------
	{
		UAshenBioAcousticHeartbeatEvaluator* HeartEvaluator = NewObject<UAshenBioAcousticHeartbeatEvaluator>();

		// Peaceful rest (out of combat, 0.0 corruption) -> 60 BPM
		const float RestBPM = HeartEvaluator->EvaluateHeartRateBPM(false, 0.0f);
		TestNearlyEqual(TEXT("Rest BPM is 60"), RestBPM, 60.0f, 0.1f);

		// Tachycardia in combat with 1.0 corruption -> 110 + 60 = 170 BPM
		const float CrisisBPM = HeartEvaluator->EvaluateHeartRateBPM(true, 1.0f);
		TestNearlyEqual(TEXT("Crisis combat BPM is 170"), CrisisBPM, 170.0f, 0.1f);

		// Audio Subsystem LPF
		UAshenBioAcousticAudioSubsystem* AudioSub = NewObject<UAshenBioAcousticAudioSubsystem>();
		const float RestLPF = AudioSub->EvaluateHeartStressAudioFilter(60.0f);
		TestNearlyEqual(TEXT("Rest LPF is 20000 Hz"), RestLPF, 20000.0f, 1.0f);

		const float CrisisLPF = AudioSub->EvaluateHeartStressAudioFilter(170.0f);
		TestNearlyEqual(TEXT("Crisis LPF is 600 Hz"), CrisisLPF, 600.0f, 1.0f);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST DUALSENSE HAPTICS & SAVEGAME PERSISTENCE
	// -----------------------------------------------------------------------------------
	{
		UAshenTraumaSomaticsHapticBridge* HapticBridge = NewObject<UAshenTraumaSomaticsHapticBridge>();
		float HeartInterval = 0.0f;
		float SlagRes = 0.0f;

		// 120 BPM -> Interval = 60 / 120 = 0.5s; Soot 0.60 -> SlagRes = 0.60 * 0.75 = 0.45
		HapticBridge->EvaluateSomaticHaptics(120.0f, 0.60f, HeartInterval, SlagRes);
		TestNearlyEqual(TEXT("120 BPM pulse interval is 0.5s"), HeartInterval, 0.50f, 0.01f);
		TestNearlyEqual(TEXT("Soot slag resistance is 0.45"), SlagRes, 0.45f, 0.01f);

		// SaveGame Adapter
		UAshenTraumaSomaticsSaveGameAdapter* SaveAdapter = NewObject<UAshenTraumaSomaticsSaveGameAdapter>();
		SaveAdapter->PackageSomatics(0.72f, 0.55f, 8, 145.0f);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredVeins = 0.0f;
		float RestoredSoot = 0.0f;
		int32 RestoredNicks = 0;
		float RestoredBPM = 0.0f;
		const bool bSuccess = SaveAdapter->RestoreSomatics(RestoredVeins, RestoredSoot, RestoredNicks, RestoredBPM);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("Restored veins is 0.72"), RestoredVeins, 0.72f, 0.01f);
		TestNearlyEqual(TEXT("Restored soot is 0.55"), RestoredSoot, 0.55f, 0.01f);
		TestEqual(TEXT("Restored nicks is 8"), RestoredNicks, 8);
		TestNearlyEqual(TEXT("Restored BPM is 145"), RestoredBPM, 145.0f, 0.1f);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
