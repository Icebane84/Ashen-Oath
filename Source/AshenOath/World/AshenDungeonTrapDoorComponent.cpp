// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 231: Ashen Dungeon Trap Door Component

#include "AshenDungeonTrapDoorComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

UAshenDungeonTrapDoorComponent::UAshenDungeonTrapDoorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	OpenDelay = 0.5f;
	bIsTriggered = false;
}

void UAshenDungeonTrapDoorComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenDungeonTrapDoorComponent::TriggerTrap(AActor* TriggeringActor)
{
	if (bIsTriggered) return;

	bIsTriggered = true;

	if (GetWorld() && OpenDelay > 0.0f)
	{
		FTimerDelegate TimerDel;
		TimerDel.BindUObject(this, &UAshenDungeonTrapDoorComponent::ExecuteTrapOpen, TriggeringActor);
		GetWorld()->GetTimerManager().SetTimer(OpenTimerHandle, TimerDel, OpenDelay, false);
	}
	else
	{
		ExecuteTrapOpen(TriggeringActor);
	}

	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonTrapDoorComponent: TRAP ARMED by '%s' — opening in %.2fs."),
		TriggeringActor ? *TriggeringActor->GetName() : TEXT("Unknown"), OpenDelay);
}

void UAshenDungeonTrapDoorComponent::ExecuteTrapOpen(AActor* TriggeringActor)
{
	OnTrapDoorTriggered.Broadcast(TriggeringActor);
	UE_LOG(LogTemp, Warning, TEXT("UAshenDungeonTrapDoorComponent: TRAPDOOR DROPPED!"));
}
