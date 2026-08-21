// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Haptics/AshenDualSenseHapticTypes.h"
#include "Haptics/AshenDualSenseHapticSubsystem.h"
#include "Haptics/AshenAdaptiveTriggerArbitratorComponent.h"
#include "Haptics/AshenControllerSpeakerWhisperComponent.h"
#include "Haptics/AshenDirectionalTactileTickComponent.h"
#include "Haptics/AshenSomaticFrictionHapticBridge.h"
#include "Core/AshenDualSenseSaveGameAdapter.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMasterBatch124AutomationTest,
	"AshenOath.Haptics.MasterBatch124_DualSenseTactile",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMasterBatch124AutomationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. TEST ADAPTIVE TRIGGER ARBITRATION (PRIORITY HIERARCHY)
	// -----------------------------------------------------------------------------------
	{
		UAshenAdaptiveTriggerArbitratorComponent* Arbitrator = NewObject<UAshenAdaptiveTriggerArbitratorComponent>();

		FDualSenseTriggerConfig SomaticConfig;
		SomaticConfig.Mode = EHapticTriggerEffectMode::Feedback;
		SomaticConfig.Priority = ETriggerPriorityLevel::Priority3_AmbientSomatic;
		SomaticConfig.ResistanceForce = 0.35f;

		FDualSenseTriggerConfig LockoutConfig;
		LockoutConfig.Mode = EHapticTriggerEffectMode::WeaponLockout;
		LockoutConfig.Priority = ETriggerPriorityLevel::Priority1_DialogueWillStruggle;
		LockoutConfig.ResistanceForce = 1.0f;

		// Incoming Lockout should override ambient somatic
		const FDualSenseTriggerConfig WinningConfig = Arbitrator->ArbitrateTriggerRequest(SomaticConfig, LockoutConfig);

		TestEqual(TEXT("Winning mode is WeaponLockout"), WinningConfig.Mode, EHapticTriggerEffectMode::WeaponLockout);
		TestEqual(TEXT("Winning priority is Priority1_DialogueWillStruggle"), WinningConfig.Priority, ETriggerPriorityLevel::Priority1_DialogueWillStruggle);
		TestNearlyEqual(TEXT("Winning force is 1.0"), WinningConfig.ResistanceForce, 1.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 2. TEST DIRECTIONAL TACTILE TICKS (FLANK THREATS)
	// -----------------------------------------------------------------------------------
	{
		UAshenDirectionalTactileTickComponent* TickComp = NewObject<UAshenDirectionalTactileTickComponent>();

		const FVector PlayerForward(1.0f, 0.0f, 0.0f);
		const FVector ThreatRight(0.0f, 1.0f, 0.0f); // 90-deg right

		float LeftMotor = 0.0f;
		float RightMotor = 0.0f;
		TickComp->CalculateDirectionalTicks(PlayerForward, ThreatRight, 0.80f, LeftMotor, RightMotor);

		TestNearlyEqual(TEXT("Right motor should be high intensity (0.80)"), RightMotor, 0.80f, 0.01f);
		TestNearlyEqual(TEXT("Left motor should be low bias (0.16)"), LeftMotor, 0.16f, 0.02f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST CONTROLLER SPEAKER WHISPER PACKAGING
	// -----------------------------------------------------------------------------------
	{
		UAshenControllerSpeakerWhisperComponent* WhisperComp = NewObject<UAshenControllerSpeakerWhisperComponent>();

		const FTactileWhisperPayload Payload = WhisperComp->PrepareWhisper(
			ETactileWhisperChannel::GarrettTactical,
			TEXT("Flank left, Kaelen! I have the wire set."),
			1.0f);

		TestEqual(TEXT("Channel is GarrettTactical"), Payload.Channel, ETactileWhisperChannel::GarrettTactical);
		TestEqual(TEXT("Dialogue matches text"), Payload.DialogueLine, FString(TEXT("Flank left, Kaelen! I have the wire set.")));
		TestTrue(TEXT("bIncludeHapticTick is true"), Payload.bIncludeHapticTick);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST SOMATIC FRICTION TRIGGER BRIDGE
	// -----------------------------------------------------------------------------------
	{
		UAshenSomaticFrictionHapticBridge* Bridge = NewObject<UAshenSomaticFrictionHapticBridge>();

		// 155kg weapon mass with 0.50 dysregulation
		const FDualSenseTriggerConfig Config = Bridge->BuildSomaticTriggerConfig(155.0f, 0.50f);

		TestEqual(TEXT("Mode is Feedback"), Config.Mode, EHapticTriggerEffectMode::Feedback);
		TestEqual(TEXT("Priority is Priority3_AmbientSomatic"), Config.Priority, ETriggerPriorityLevel::Priority3_AmbientSomatic);
		TestTrue(TEXT("ResistanceForce is in high resistance range (>0.50)"), Config.ResistanceForce >= 0.50f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST DUALSENSE SAVEGAME ADAPTER
	// -----------------------------------------------------------------------------------
	{
		UAshenDualSenseSaveGameAdapter* SaveAdapter = NewObject<UAshenDualSenseSaveGameAdapter>();

		SaveAdapter->PackageHapticSettings(0.80f, 0.90f, false);
		TestTrue(TEXT("HasSavedData is true"), SaveAdapter->HasSavedData());

		float RestoredIntensity = 0.0f;
		float RestoredVolume = 0.0f;
		bool bRestoredDisableLockouts = true;
		const bool bSuccess = SaveAdapter->RestoreHapticSettings(RestoredIntensity, RestoredVolume, bRestoredDisableLockouts);

		TestTrue(TEXT("Restore succeeded"), bSuccess);
		TestNearlyEqual(TEXT("TriggerIntensity restored"), RestoredIntensity, 0.80f, 0.01f);
		TestNearlyEqual(TEXT("SpeakerVolume restored"), RestoredVolume, 0.90f, 0.01f);
		TestFalse(TEXT("bDisableHardLockouts restored"), bRestoredDisableLockouts);
	}

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
