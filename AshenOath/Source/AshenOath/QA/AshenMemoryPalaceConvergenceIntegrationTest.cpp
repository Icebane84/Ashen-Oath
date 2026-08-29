// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "CoreMinimal.h"
#include "Misc/AutomationTest.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"
#include "Memory/AshenMemoryPalaceGraphSubsystem.h"
#include "Memory/AshenMemoryPalaceNodeAnchorActor.h"
#include "Memory/AshenMemoryBattleSubsystem.h"
#include "Memory/AshenIntegrationDebtAccumulatorSubsystem.h"
#include "Companions/AshenDevilsBargainTrustAtrophyDirector.h"
#include "Combat/AshenCombatCharacter.h"
#include "Combat/AshenOath_SanityComponent.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(
	FAshenMemoryPalaceConvergenceIntegrationTest,
	"AshenOath.Convergence.MemoryPalace.CausalFlowAndIntegrationDebt",
	EAutomationTestFlags::EditorContext | EAutomationTestFlags::ProductFilter)

bool FAshenMemoryPalaceConvergenceIntegrationTest::RunTest(const FString& Parameters)
{
	// -----------------------------------------------------------------------------------
	// 1. SETUP TRANSIENT WORLD & GAME INSTANCE
	// -----------------------------------------------------------------------------------
	UWorld* World = UWorld::CreateWorld(EWorldType::Game, false, TEXT("MemoryPalaceConvergenceTestWorld"));
	TestNotNull(TEXT("Transient World created"), World);
	if (!World)
	{
		return false;
	}

	UGameInstance* GameInstance = NewObject<UGameInstance>(World);
	GameInstance->Init();
	World->SetGameInstance(GameInstance);

	UAshenMemoryPalaceGraphSubsystem* GraphSubsystem = GameInstance->GetSubsystem<UAshenMemoryPalaceGraphSubsystem>();
	TestNotNull(TEXT("UAshenMemoryPalaceGraphSubsystem exists on GameInstance"), GraphSubsystem);

	UAshenDevilsBargainTrustAtrophyDirector* TrustDirector = GameInstance->GetSubsystem<UAshenDevilsBargainTrustAtrophyDirector>();
	TestNotNull(TEXT("UAshenDevilsBargainTrustAtrophyDirector exists on GameInstance"), TrustDirector);

	UAshenMemoryBattleSubsystem* BattleSubsystem = World->GetSubsystem<UAshenMemoryBattleSubsystem>();
	TestNotNull(TEXT("UAshenMemoryBattleSubsystem exists on World"), BattleSubsystem);

	UAshenIntegrationDebtAccumulatorSubsystem* DebtSubsystem = World->GetSubsystem<UAshenIntegrationDebtAccumulatorSubsystem>();
	TestNotNull(TEXT("UAshenIntegrationDebtAccumulatorSubsystem exists on World"), DebtSubsystem);

	// Spawn Player Character (Kaelen)
	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	AAshenCombatCharacter* Kaelen = World->SpawnActor<AAshenCombatCharacter>(AAshenCombatCharacter::StaticClass(), FVector(0, 0, 100), FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("Kaelen combat character spawned"), Kaelen);

	UAshenOath_SanityComponent* SanityComp = Kaelen ? Kaelen->FindComponentByClass<UAshenOath_SanityComponent>() : nullptr;
	TestNotNull(TEXT("Kaelen sanity component exists"), SanityComp);

	// -----------------------------------------------------------------------------------
	// 2. TEST DORMANT MEMORY ANCHOR INSTANT UNSEAL & BASELINE RECOVERY
	// -----------------------------------------------------------------------------------
	if (GraphSubsystem && Kaelen && SanityComp)
	{
		SanityComp->SetCurrentSanity(50.0f);

		AAshenMemoryPalaceNodeAnchorActor* DormantAnchor = World->SpawnActor<AAshenMemoryPalaceNodeAnchorActor>(
			AAshenMemoryPalaceNodeAnchorActor::StaticClass(), FVector(200, 0, 0), FRotator::ZeroRotator, SpawnParams);
		TestNotNull(TEXT("Dormant anchor actor spawned"), DormantAnchor);

		if (DormantAnchor)
		{
			DormantAnchor->AnchoredMemoryID = FName(TEXT("Node.Dormant.HavenRest"));
			DormantAnchor->TraumaLevel = EMemoryTraumaLevel::Dormant;
			DormantAnchor->NodeType = EMemoryNodeType::EchoLocus;

			const bool bInteracted = DormantAnchor->InteractWithAnchor(Kaelen);
			TestTrue(TEXT("Dormant anchor interaction succeeded"), bInteracted);

			FMemoryGraphNode ResultNode;
			const bool bNodeFound = GraphSubsystem->GetNode(FName(TEXT("Node.Dormant.HavenRest")), ResultNode);
			TestTrue(TEXT("Dormant memory node registered in graph"), bNodeFound);
			TestTrue(TEXT("Dormant memory node is unsealed"), ResultNode.bIsUnsealed);
			TestNearlyEqual(TEXT("Kaelen sanity healed +10 from dormant memory"), SanityComp->GetCurrentSanity(), 60.0f, 0.01f);

			DormantAnchor->Destroy();
		}
	}

	// -----------------------------------------------------------------------------------
	// 3. TEST TRAUMATIC MEMORY BATTLE VICTORY & TRIPARTITE CATHARSIS LOOP
	// -----------------------------------------------------------------------------------
	if (GraphSubsystem && BattleSubsystem && TrustDirector && Kaelen && SanityComp)
	{
		SanityComp->SetCurrentSanity(50.0f);
		TrustDirector->ActivePartyTrustLevel = 80.0f;

		AAshenMemoryPalaceNodeAnchorActor* TraumaAnchor = World->SpawnActor<AAshenMemoryPalaceNodeAnchorActor>(
			AAshenMemoryPalaceNodeAnchorActor::StaticClass(), FVector(500, 0, 0), FRotator::ZeroRotator, SpawnParams);
		TestNotNull(TEXT("Trauma anchor actor spawned"), TraumaAnchor);

		if (TraumaAnchor)
		{
			TraumaAnchor->AnchoredMemoryID = FName(TEXT("Node.Trauma.SunderedGate"));
			TraumaAnchor->TraumaLevel = EMemoryTraumaLevel::Severe;
			TraumaAnchor->NodeType = EMemoryNodeType::TraumaNexus;
			TraumaAnchor->ResonancePower = 150.0f;

			// Interacting triggers Memory Battle initiation
			const bool bInteracted = TraumaAnchor->InteractWithAnchor(Kaelen);
			TestTrue(TEXT("Traumatic anchor triggered Memory Battle"), bInteracted);
			TestTrue(TEXT("Memory battle is active"), BattleSubsystem->bIsMemoryBattleActive);
			TestEqual(TEXT("Active echo matches trauma anchor ID"), BattleSubsystem->ActiveEchoID, FName(TEXT("Node.Trauma.SunderedGate")));

			// Simulate Battle Victory
			BattleSubsystem->ConcludeMemoryBattleForCharacter(true, Kaelen);

			TestFalse(TEXT("Memory battle concluded"), BattleSubsystem->bIsMemoryBattleActive);

			FMemoryGraphNode ResultNode;
			const bool bNodeFound = GraphSubsystem->GetNode(FName(TEXT("Node.Trauma.SunderedGate")), ResultNode);
			TestTrue(TEXT("Trauma memory node registered in graph"), bNodeFound);
			TestTrue(TEXT("Trauma memory node unsealed on victory"), ResultNode.bIsUnsealed);
			TestNearlyEqual(TEXT("Kaelen sanity healed +25 on battle victory"), SanityComp->GetCurrentSanity(), 75.0f, 0.01f);
			TestNearlyEqual(TEXT("Companion party trust restored +5% (85.0%)"), TrustDirector->ActivePartyTrustLevel, 85.0f, 0.01f);

			TraumaAnchor->Destroy();
		}
	}

	// -----------------------------------------------------------------------------------
	// 4. TEST TRAUMATIC MEMORY BATTLE DEFEAT & INTEGRATION DEBT PRESSURE
	// -----------------------------------------------------------------------------------
	if (GraphSubsystem && BattleSubsystem && DebtSubsystem && Kaelen && SanityComp)
	{
		SanityComp->SetCurrentSanity(75.0f);

		// Initiate new contested battle
		BattleSubsystem->InitiateMemoryBattle(FName(TEXT("Node.Trauma.FracturedMemory")), 80.0f, false);
		TestTrue(TEXT("Contested memory battle initiated"), BattleSubsystem->bIsMemoryBattleActive);

		// Simulate Battle Defeat
		BattleSubsystem->ConcludeMemoryBattleForCharacter(false, Kaelen);

		TestFalse(TEXT("Memory battle concluded"), BattleSubsystem->bIsMemoryBattleActive);

		FMemoryGraphNode ResultNode;
		if (GraphSubsystem->GetNode(FName(TEXT("Node.Trauma.FracturedMemory")), ResultNode))
		{
			TestFalse(TEXT("Defeated memory node remains sealed"), ResultNode.bIsUnsealed);
		}

		TestNearlyEqual(TEXT("Kaelen suffered -30 mental damage on defeat (45.0)"), SanityComp->GetCurrentSanity(), 45.0f, 0.01f);
		TestNearlyEqual(TEXT("Integration debt accumulated +20% (0.20)"), DebtSubsystem->GetIntegrationDebt(), 0.20f, 0.01f);
	}

	// Cleanup
	if (Kaelen)
	{
		Kaelen->Destroy();
	}
	World->DestroyWorld(false);
	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
