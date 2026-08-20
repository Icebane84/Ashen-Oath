// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 444: Ashen Vertical Slice Master Director Subsystem

#include "AshenVerticalSliceMasterDirectorSubsystem.h"
#include "AshenFullPsychologicalLoopOrchestratorComponent.h"

void UAshenVerticalSliceMasterDirectorSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	UE_LOG(LogTemp, Log, TEXT("UAshenVerticalSliceMasterDirectorSubsystem: Initialized — Vertical Slice Master Director ONLINE."));
}

bool UAshenVerticalSliceMasterDirectorSubsystem::TriggerVerticalSlicePass(AActor* PlayerActor, AActor* TargetEnemyActor)
{
	if (!PlayerActor) return false;

	UAshenFullPsychologicalLoopOrchestratorComponent* LoopOrchestrator = PlayerActor->FindComponentByClass<UAshenFullPsychologicalLoopOrchestratorComponent>();
	if (!LoopOrchestrator)
	{
		LoopOrchestrator = NewObject<UAshenFullPsychologicalLoopOrchestratorComponent>(PlayerActor);
		LoopOrchestrator->RegisterComponent();
	}

	bool bSuccess = LoopOrchestrator->ExecuteFullPsychologicalLoop(TargetEnemyActor);
	OnVerticalSliceCompleted.Broadcast(bSuccess);

	UE_LOG(LogTemp, Warning, TEXT("UAshenVerticalSliceMasterDirectorSubsystem: VERTICAL SLICE LOOP TRIGGERED — Result: %s"),
		bSuccess ? TEXT("SUCCESS") : TEXT("FAILED"));

	return bSuccess;
}
