// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 369: Ashen Gaslighting Ghouls Enemy Component

#include "AshenGaslightingGhoulsEnemyComponent.h"

UAshenGaslightingGhoulsEnemyComponent::UAshenGaslightingGhoulsEnemyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenGaslightingGhoulsEnemyComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenGaslightingGhoulsEnemyComponent::TriggerGaslightingAttack()
{
	const FName GaslightTag(TEXT("Gaslight_AuditoryDissonance"));
	const int32 Clones = 3;

	OnGaslightingAttackTriggered.Broadcast(GaslightTag, Clones);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGaslightingGhoulsEnemyComponent: GASLIGHTING ATTACK TRIGGERED — Spawning %d Phantom Clones."), Clones);
}
