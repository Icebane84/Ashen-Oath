// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_SanityComponent.h"
#include "Combat/AshenOath_PoiseComponent.h"
#include "Combat/AshenWeaveAegisNetGASAbility.h"
#include "Combat/AshenWeaveTraumaBridgeGASAbility.h"
#include "Combat/AshenActiveMemoryWeavingSubsystem.h"
#include "World/AshenMemoryPalaceWeavingLocusActor.h"
#include "Memory/AshenMemoryPalaceGraphSubsystem.h"
#include "Companions/AshenCompanionFatigueSubsystem.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMemoryWeavingConvergenceIntegrationTest,
	"AshenOath.Convergence.MemoryWeaving.AegisBridgeAndLoom",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMemoryWeavingConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("MemoryWeavingTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenCompanionFatigueSubsystem* FatigueSubsystem = GameInstance->GetSubsystem<UAshenCompanionFatigueSubsystem>();
	UAshenActiveMemoryWeavingSubsystem* LoomSubsystem = GameInstance->GetSubsystem<UAshenActiveMemoryWeavingSubsystem>();
	UAshenMemoryPalaceGraphSubsystem* GraphSubsystem = GameInstance->GetSubsystem<UAshenMemoryPalaceGraphSubsystem>();

	TestNotNull(TEXT("UAshenCompanionFatigueSubsystem exists"), FatigueSubsystem);
	TestNotNull(TEXT("UAshenActiveMemoryWeavingSubsystem exists"), LoomSubsystem);
	TestNotNull(TEXT("UAshenMemoryPalaceGraphSubsystem exists"), GraphSubsystem);

	// Spawn Player Character (Kaelen)
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* Kaelen = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Kaelen combat character spawned"), Kaelen);

	UAshenOath_SanityComponent* SanityComp = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_SanityComponent>() : nullptr;
	UAshenOath_PoiseComponent* PoiseComp = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_PoiseComponent>() : nullptr;
	TestNotNull(TEXT("Kaelen sanity component exists"), SanityComp);
	TestNotNull(TEXT("Kaelen poise component exists"), PoiseComp);

	// -----------------------------------------------------------------------------------
	// 2. TEST AEGIS NET HYPERARMOR & SERAFINA FATIGUE
	// -----------------------------------------------------------------------------------
	if (Kaelen && PoiseComp && FatigueSubsystem)
	{
		FatigueSubsystem->ResetAllFatigue();
		PoiseComp->SetHyperArmorActive(false);

		UAshenWeaveAegisNetGASAbility* AegisAbility = NewObject<UAshenWeaveAegisNetGASAbility>(Kaelen);
		TestNotNull(TEXT("Aegis Net ability instantiated"), AegisAbility);

		const bool bAegisSuccess = AegisAbility->DeployAegisNetOnTarget(Kaelen);
		TestTrue(TEXT("Aegis Net successfully deployed"), bAegisSuccess);

		// Assert HyperArmor active
		TestTrue(TEXT("HyperArmor active on Kaelen posture"), PoiseComp->IsHyperArmorActive());

		// Assert Serafina Fatigue accumulated +0.15
		TestNearlyEqual(TEXT("Serafina fatigue is 0.15"), FatigueSubsystem->SerafinaFatigue, 0.15f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST TRAUMA LIGHT BRIDGE SPAN & SANITY HEAL
	// -----------------------------------------------------------------------------------
	if (Kaelen && SanityComp && FatigueSubsystem)
	{
		SanityComp->SetCurrentSanity(50.0f);

		UAshenWeaveTraumaBridgeGASAbility* BridgeAbility = NewObject<UAshenWeaveTraumaBridgeGASAbility>(Kaelen);
		TestNotNull(TEXT("Trauma Bridge ability instantiated"), BridgeAbility);

		// Test successful bridge manifest (<1200uu)
		const bool bBridgeSuccess = BridgeAbility->ManifestTraumaBridge(Kaelen, FVector(0, 0, 0), FVector(600, 0, 0));
		TestTrue(TEXT("Trauma bridge manifested for 600uu span"), bBridgeSuccess);

		// Assert Sanity healed +15 (50 -> 65)
		TestNearlyEqual(TEXT("Sanity healed to 65.0"), SanityComp->GetCurrentSanity(), 65.0f, 0.01f);

		// Assert Serafina Fatigue accumulated +0.15 (0.15 -> 0.30)
		TestNearlyEqual(TEXT("Serafina fatigue is 0.30"), FatigueSubsystem->SerafinaFatigue, 0.30f, 0.01f);

		// Test bridge rejection over max span (>1200uu)
		const bool bBridgeExcessive = BridgeAbility->ManifestTraumaBridge(Kaelen, FVector(0, 0, 0), FVector(1500, 0, 0));
		TestFalse(TEXT("Excessive bridge span rejected"), bBridgeExcessive);
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST ACTIVE MEMORY LOOM DENSITY & THREAD SNAP BACKLASH
	// -----------------------------------------------------------------------------------
	if (LoomSubsystem && SanityComp && Kaelen)
	{
		int32 OutThreads = 0;
		float OutTension = 0.0f;

		// Calculate density: IntegrationDebt = 0.90, Trust = 0.75 -> Threads = 4 + 12 = 16, Tension = 0.20 + 0.72 = 0.92
		LoomSubsystem->CalculateWeavingDensity(0.90f, 0.75f, OutThreads, OutTension);
		TestEqual(TEXT("Weaving thread count is 16"), OutThreads, 16);
		TestNearlyEqual(TEXT("Weaving thread tension is 0.92"), OutTension, 0.92f, 0.01f);

		// Register Thread Snap Event (Tension > 0.80)
		const bool bSnapSuccess = LoomSubsystem->RegisterThreadSnapEvent(Kaelen);
		TestTrue(TEXT("Thread snap event executed"), bSnapSuccess);

		// Assert -15.0 Sanity mental backlash (65.0 -> 50.0)
		TestNearlyEqual(TEXT("Sanity damaged by -15.0 backlash (50.0)"), SanityComp->GetCurrentSanity(), 50.0f, 0.01f);
	}

	// -----------------------------------------------------------------------------------
	// 5. TEST MEMORY WEAVING LOCUS UNSEALING & REWARD
	// -----------------------------------------------------------------------------------
	if (World && GraphSubsystem && SanityComp && Kaelen)
	{
		AAshenMemoryPalaceWeavingLocusActor* Locus = World->SpawnActor<AAshenMemoryPalaceWeavingLocusActor>(AAshenMemoryPalaceWeavingLocusActor::StaticClass());
		TestNotNull(TEXT("Memory Weaving Locus actor spawned"), Locus);

		if (Locus)
		{
			FMemoryGraphNode Node;
			Node.NodeID = Locus->BoundMemoryNodeTag;
			Node.bIsUnsealed = false;
			GraphSubsystem->RegisterNode(Node);

			Locus->ExecuteMemoryWeavingPass(true, Kaelen);

			// Assert Node unsealed in graph
			FMemoryGraphNode OutNode;
			const bool bFound = GraphSubsystem->GetNode(Locus->BoundMemoryNodeTag, OutNode);
			TestTrue(TEXT("Locus node found in graph"), bFound);
			TestTrue(TEXT("Locus node successfully unsealed in graph"), OutNode.bIsUnsealed);

			// Assert Sanity healed +20 (50 -> 70)
			TestNearlyEqual(TEXT("Sanity healed to 70.0 upon weaving locus"), SanityComp->GetCurrentSanity(), 70.0f, 0.01f);

			// Assert Locus marked weaved
			TestTrue(TEXT("Locus is marked weaved"), Locus->bIsWeaved);

			Locus->Destroy();
		}
	}

	// Cleanup
	if (Kaelen) Kaelen->Destroy();
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
