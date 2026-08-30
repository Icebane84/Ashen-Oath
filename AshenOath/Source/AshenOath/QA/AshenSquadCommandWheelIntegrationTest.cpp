// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenSquadCommandWheelComponent.h"
#include "Combat/AshenCompanionTacticalOrderAbility.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulTypes.h"
#include "Soul/AshenSoulStateVector.h"

#if WITH_DEV_AUTOMATION_TESTS

// -----------------------------------------------------------------------------
// 1. UNIT TEST: Bullet-Time Dilation Toggle & Initial State
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSquadCommandWheelUnitTest,
	"AshenOath.SquadCommand.Unit.TimeDilationToggle",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenSquadCommandWheelUnitTest::RunTest(const FString& Parameters)
{
	UAshenSquadCommandWheelComponent* Wheel = NewObject<UAshenSquadCommandWheelComponent>();
	TestNotNull(TEXT("Command wheel component created"), Wheel);

	if (Wheel)
	{
		TestFalse(TEXT("Wheel starts closed"), Wheel->IsCommandWheelOpen());
		TestEqual(TEXT("Default bullet-time dilation is 0.20"), Wheel->GetBulletTimeDilation(), 0.20f);
	}

	return true;
}

// -----------------------------------------------------------------------------
// 2. INTEGRATION TEST: Multi-Dimensional Relational Matrix Command Gating
// -----------------------------------------------------------------------------
IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenSquadCommandWheelIntegrationTest,
	"AshenOath.SquadCommand.Integration.RelationalMatrixGating",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenSquadCommandWheelIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("SquadCommandTestWorld"));
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
			UAshenSquadCommandWheelComponent* Wheel = NewObject<UAshenSquadCommandWheelComponent>(World);
			TestNotNull(TEXT("Wheel component created in world"), Wheel);

			if (Wheel)
			{
				// Test 1: Garrett High Somatic Dread (0.75) forces Caltrop Snare fallback
				FRelationalMatrix_V2 MatrixWithHighDread;
				MatrixWithHighDread.GarrettProfile.TacticalConfidence = 0.50f;
				MatrixWithHighDread.GarrettProfile.SomaticDread = 0.75f; // High Fear!
				Publisher->SetRelationalMatrix(MatrixWithHighDread);

				EAshenSquadCommand DispatchedCmd = EAshenSquadCommand::Garrett_PauldronVault;
				bool bDispatchedFallback = false;

				Wheel->OnSquadOrderDispatchedNative.AddLambda([&](EAshenSquadCommand Cmd, bool bFallback) {
					DispatchedCmd = Cmd;
					bDispatchedFallback = bFallback;
				});

				Wheel->ExecuteSquadCommand(EAshenSquadCommand::Garrett_PauldronVault, nullptr);

				TestEqual(TEXT("High dread forces fallback to Caltrop Snare"), DispatchedCmd, EAshenSquadCommand::Garrett_CaltropSnare);
				TestTrue(TEXT("Fallback flag is true"), bDispatchedFallback);

				// Test 2: Serafina High Burnout (0.85) locks Conduit Burst and executes Aegis Barrier
				FRelationalMatrix_V2 MatrixWithHighBurnout;
				MatrixWithHighBurnout.SerafinaProfile.TransferenceBurnout = 0.85f; // High Burnout!
				Publisher->SetRelationalMatrix(MatrixWithHighBurnout);

				Wheel->ExecuteSquadCommand(EAshenSquadCommand::Serafina_ConduitBurst, nullptr);

				TestEqual(TEXT("High burnout forces fallback to Aegis Barrier"), DispatchedCmd, EAshenSquadCommand::Serafina_AegisBarrier);
				TestTrue(TEXT("Fallback flag is true for burnout"), bDispatchedFallback);
			}
		}
	}

	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
