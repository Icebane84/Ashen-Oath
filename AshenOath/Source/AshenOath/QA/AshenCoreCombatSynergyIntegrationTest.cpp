// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenSovereignDualityTransformationAbility.h"
#include "World/AshenSanctuaryField.h"
#include "Combat/AshenSerafinaSacredBarrierGASAbility.h"
#include "Combat/AshenGarrettFlankAssistAbility.h"
#include "Combat/AshenOathbringerRiposteAbility.h"
#include "World/AshenDualityShaderShiftComponent.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"
#include "Combat/AshenOath_StaminaComponent.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenCoreCombatSynergyIntegrationTest,
	"AshenOath.Convergence.CoreCombatSynergyMatrix",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenCoreCombatSynergyIntegrationTest::RunTest(const FString& Parameters)
{
	UWorld* World = nullptr;
	const TIndirectArray<FWorldContext>& WorldContexts = GEngine->GetWorldContexts();
	for (const FWorldContext& Context : WorldContexts)
	{
		if (Context.World() && Context.World()->IsGameWorld())
		{
			World = Context.World();
			break;
		}
	}
	if (!World && WorldContexts.Num() > 0)
	{
		World = WorldContexts[0].World();
	}

	TestNotNull(TEXT("World context exists"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = World->GetGameInstance();
	TestNotNull(TEXT("GameInstance exists"), GameInstance);
	if (!GameInstance)
	{
		return false;
	}

	UAshenCompanionFatigueSubsystem* FatigueSubsystem = GameInstance->GetSubsystem<UAshenCompanionFatigueSubsystem>();
	TestNotNull(TEXT("UAshenCompanionFatigueSubsystem exists"), FatigueSubsystem);
	if (FatigueSubsystem)
	{
		FatigueSubsystem->ResetAllFatigue();
	}

	// -----------------------------------------------------------------------------------
	// 1. SPAWN ACTORS
	// -----------------------------------------------------------------------------------
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	AAshenCombatCharacter* Kaelen = World->SpawnActor<AAshenCombatCharacter>(
		AAshenCombatCharacter::StaticClass(),
		FVector(0.0f, 0.0f, 100.0f),
		FRotator::ZeroRotator,
		SpawnParams
	);
	TestNotNull(TEXT("Kaelen spawned"), Kaelen);

	AAshenCombatCharacter* TargetDummy = World->SpawnActor<AAshenCombatCharacter>(
		AAshenCombatCharacter::StaticClass(),
		FVector(500.0f, 0.0f, 100.0f),
		FRotator::ZeroRotator,
		SpawnParams
	);
	TestNotNull(TEXT("TargetDummy spawned"), TargetDummy);

	if (!Kaelen || !TargetDummy)
	{
		if (Kaelen) Kaelen->Destroy();
		if (TargetDummy) TargetDummy->Destroy();
		return false;
	}

	// -----------------------------------------------------------------------------------
	// 2. SYSTEM 1: DUALITY TRANSFORMATION ABILITY (PHASE 2 BLEND RATIO TO 1.0)
	// -----------------------------------------------------------------------------------
	{
		UAshenSovereignDualityTransformationAbility* DualityAbility = NewObject<UAshenSovereignDualityTransformationAbility>(Kaelen);
		const bool bPulseSuccess = DualityAbility->TriggerDualityTransformationPulse();
		TestTrue(TEXT("Duality pulse executed"), bPulseSuccess);

		UAshenDualityShaderShiftComponent* ShaderShift = Kaelen->GetDualityShaderShiftComponent();
		TestNotNull(TEXT("ShaderShiftComponent exists"), ShaderShift);
		if (ShaderShift)
		{
			TestNearlyEqual(TEXT("Duality blend ratio interpolated to 1.0f"), ShaderShift->CurrentDualityBlendRatio, 1.0f, 0.01f);
		}
	}

	// -----------------------------------------------------------------------------------
	// 3. SYSTEM 2: SERAFINA SACRED BARRIER & AAshenSanctuaryField OVERLAP (+250% STAMINA)
	// -----------------------------------------------------------------------------------
	{
		UAshenSerafinaSacredBarrierGASAbility* BarrierAbility = NewObject<UAshenSerafinaSacredBarrierGASAbility>(Kaelen);
		AAshenSanctuaryField* FieldActor = BarrierAbility->SpawnSacredBarrier(Kaelen->GetActorLocation());
		TestNotNull(TEXT("Sanctuary Field actor spawned"), FieldActor);

		if (FieldActor)
		{
			UAshenOath_StaminaComponent* StaminaComp = Kaelen->FindComponentByClass<UAshenOath_StaminaComponent>();
			TestNotNull(TEXT("Kaelen stamina component exists"), StaminaComp);

			const float OriginalRegen = StaminaComp ? StaminaComp->GetRegenRate() : 10.0f;

			// Simulate Overlap
			FieldActor->OnFieldBeginOverlap(nullptr, Kaelen, nullptr, 0, false, FHitResult());

			TestTrue(TEXT("Kaelen protected by sanctuary field"), FieldActor->IsActorProtectedBySanctuary(Kaelen));
			if (StaminaComp)
			{
				TestNearlyEqual(TEXT("Stamina regen accelerated by +250% (3.5x)"), StaminaComp->GetRegenRate(), OriginalRegen * 3.5f, 0.1f);
			}

			if (FatigueSubsystem)
			{
				TestNearlyEqual(TEXT("Serafina fatigue accumulated to 0.20"), FatigueSubsystem->SerafinaFatigue, 0.20f, 0.01f);
			}

			// Clean up field overlap
			FieldActor->OnFieldEndOverlap(nullptr, Kaelen, nullptr, 0);
			FieldActor->Destroy();
		}
	}

	// -----------------------------------------------------------------------------------
	// 4. SYSTEM 3: GARRETT FLANK ASSIST (MOTION WARP & 1.8X STAGGER VS RECOVERY)
	// -----------------------------------------------------------------------------------
	{
		UAshenGarrettFlankAssistAbility* FlankAbility = NewObject<UAshenGarrettFlankAssistAbility>(Kaelen);
		const bool bFlankSuccess = FlankAbility->ExecuteFlankAssist(TargetDummy, true); // Target in Recovery state
		TestTrue(TEXT("Garrett flank assist executed"), bFlankSuccess);

		const FVector ExpectedRear = TargetDummy->GetActorLocation() - (TargetDummy->GetActorForwardVector() * 150.0f);
		TestNearlyEqual(TEXT("Motion warped to target rear X"), (float)FlankAbility->LastWarpDestination.X, (float)ExpectedRear.X, 1.0f);
		TestNearlyEqual(TEXT("Motion warped to target rear Y"), (float)FlankAbility->LastWarpDestination.Y, (float)ExpectedRear.Y, 1.0f);

		if (FatigueSubsystem)
		{
			TestNearlyEqual(TEXT("Garrett fatigue accumulated to 0.25"), FatigueSubsystem->GarrettFatigue, 0.25f, 0.01f);
		}
	}

	// -----------------------------------------------------------------------------------
	// 5. SYSTEM 4: OATHBRINGER RIPOSTE (PAIRED EXECUTION & POSTURE RESET)
	// -----------------------------------------------------------------------------------
	{
		UAshenOathbringerRiposteAbility* RiposteAbility = NewObject<UAshenOathbringerRiposteAbility>(Kaelen);
		const bool bRiposteSuccess = RiposteAbility->ExecuteRiposte(TargetDummy, true); // Target staggered
		TestTrue(TEXT("Riposte execution succeeded"), bRiposteSuccess);

		const FVector ExpectedFront = TargetDummy->GetActorLocation() + (TargetDummy->GetActorForwardVector() * 120.0f);
		TestNearlyEqual(TEXT("Synced to target front X"), (float)RiposteAbility->LastExecutionPosition.X, (float)ExpectedFront.X, 1.0f);
		TestNearlyEqual(TEXT("Synced to target front Y"), (float)RiposteAbility->LastExecutionPosition.Y, (float)ExpectedFront.Y, 1.0f);
	}

	// Cleanup
	Kaelen->Destroy();
	TargetDummy->Destroy();

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
