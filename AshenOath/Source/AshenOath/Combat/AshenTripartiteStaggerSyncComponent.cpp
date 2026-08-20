// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTripartiteStaggerSyncComponent.h"

UAshenTripartiteStaggerSyncComponent::UAshenTripartiteStaggerSyncComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsTrioConverged = false;
}
void UAshenTripartiteStaggerSyncComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenTripartiteStaggerSyncComponent::ConvergeTrioOnTarget(AActor* BossActor)
{
	if (!BossActor) return false;
	bIsTrioConverged = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenTripartiteStaggerSyncComponent: TRIO CONVERGED ON STAGGERED BOSS: %s!"), *BossActor->GetName());
	return true;
}
