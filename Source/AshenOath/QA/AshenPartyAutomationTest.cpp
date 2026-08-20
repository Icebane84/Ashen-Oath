// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Misc/AutomationTest.h"
#include "AshenPartyOrchestratorComponent.h"
#include "AshenOath_TrustAccumulationComponent.h"
#include "AshenOath_AlchemicalComponent.h"
#include "AshenOath_WardenComponent.h"
#include "AshenCompanionAIComponent.h"
#include "AshenOath_PoiseComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

#if WITH_DEV_AUTOMATION_TESTS

IMPLEMENT_SIMPLE_AUTOMATION_TEST(FAshenPartyAutomationTest, "AshenOath.Party.FullTrioOrchestrationCycle", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FAshenPartyAutomationTest::RunTest(const FString& Parameters)
{
	// 1. Create dummy world and host actor
	UWorld* World = UWorld::CreateWorld(EWorldType::None, false);
	TestNotNull(TEXT("World must be created"), World);
	if (!World)
	{
		return false;
	}

	FActorSpawnParameters SpawnParams;
	AActor* HostActor = World->SpawnActor<AActor>(AActor::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("HostActor must be created"), HostActor);
	if (!HostActor)
	{
		World->DestroyWorld(false);
		return false;
	}

	// 2. Attach required components
	UAshenOath_TrustAccumulationComponent* TrustComp = NewObject<UAshenOath_TrustAccumulationComponent>(HostActor);
	TrustComp->RegisterComponent();

	UAshenOath_AlchemicalComponent* AlchemComp = NewObject<UAshenOath_AlchemicalComponent>(HostActor);
	AlchemComp->RegisterComponent();

	UAshenOath_WardenComponent* WardenComp = NewObject<UAshenOath_WardenComponent>(HostActor);
	WardenComp->RegisterComponent();

	UAshenCompanionAIComponent* CompanionAIComp = NewObject<UAshenCompanionAIComponent>(HostActor);
	CompanionAIComp->RegisterComponent();

	UAshenPartyOrchestratorComponent* PartyOrchestrator = NewObject<UAshenPartyOrchestratorComponent>(HostActor);
	PartyOrchestrator->RegisterComponent();

	// 3. Verify component bindings
	TestNotNull(TEXT("TrustComponent must be bound"), PartyOrchestrator->TrustComponent.Get());
	TestNotNull(TEXT("AlchemicalComponent must be bound"), PartyOrchestrator->AlchemicalComponent.Get());
	TestNotNull(TEXT("WardenComponent must be bound"), PartyOrchestrator->WardenComponent.Get());
	TestNotNull(TEXT("CompanionAIComponent must be bound"), PartyOrchestrator->CompanionAIComponent.Get());

	// 4. Test directional trust initialization
	FAshenOathTrustPairKey KeyKG(EAshenOathCompanion::Kaelen, EAshenOathCompanion::Garrett);
	FAshenOathTrustPairKey KeyKS(EAshenOathCompanion::Kaelen, EAshenOathCompanion::Serafina);

	TrustComp->InitializePairTrust(KeyKG, 0.85f);
	TrustComp->InitializePairTrust(KeyKS, 0.85f);

	TestTrue(TEXT("Trio should be synchronized"), PartyOrchestrator->IsTrioSynchronized());

	// 5. Create dummy enemy actor and execute Resonant Cleave Finisher
	AActor* EnemyActor = World->SpawnActor<AActor>(AActor::StaticClass(), FVector(500.f, 0.f, 0.f), FRotator::ZeroRotator, SpawnParams);
	TestNotNull(TEXT("EnemyActor must be created"), EnemyActor);

	bool bFinisherSuccess = PartyOrchestrator->ExecuteResonantCleaveFinisher(EnemyActor);
	TestTrue(TEXT("Resonant Cleave Finisher must succeed when Synchronized"), bFinisherSuccess);
	TestTrue(TEXT("Symbiotic Flow State must be active"), CompanionAIComp->bSymbioticResonanceActive);

	// 6. Execute Sentinel's Bulwark Combo
	bool bBulwarkSuccess = PartyOrchestrator->ExecuteSentinelsBulwarkCombo(EnemyActor);
	TestTrue(TEXT("Sentinel's Bulwark Combo must succeed"), bBulwarkSuccess);

	// Cleanup
	HostActor->Destroy();
	EnemyActor->Destroy();
	World->DestroyWorld(false);

	return true;
}

#endif // WITH_DEV_AUTOMATION_TESTS
