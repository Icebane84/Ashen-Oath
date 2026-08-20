// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenConcealmentComponent.h"
#include "AshenOath_ThreatPerceptionComponent.h"
#include "GameFramework/Actor.h"
#include "TimerManager.h"
#include "Engine/World.h"

UAshenConcealmentComponent::UAshenConcealmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsConcealed = false;
}

void UAshenConcealmentComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenConcealmentComponent::EnterConcealment(float Duration)
{
	if (bIsConcealed)
	{
		// Extend duration if already concealed
		if (GetWorld())
		{
			GetWorld()->GetTimerManager().ClearTimer(ConcealmentTimerHandle);
			GetWorld()->GetTimerManager().SetTimer(ConcealmentTimerHandle, this, &UAshenConcealmentComponent::ExitConcealment, Duration, false);
		}
		return;
	}

	bIsConcealed = true;
	AActor* OwnerActor = GetOwner();

	// Lower threat perception profile
	if (OwnerActor)
	{
		UE_LOG(LogTemp, Log, TEXT("UAshenConcealmentComponent: Threat dropped for '%s'"), *OwnerActor->GetName());
	}

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().SetTimer(ConcealmentTimerHandle, this, &UAshenConcealmentComponent::ExitConcealment, Duration, false);
	}

	OnConcealmentStateChanged.Broadcast(true);
	UE_LOG(LogTemp, Warning, TEXT("UAshenConcealmentComponent: Actor '%s' entered smoke balm concealment (%.1fs)!"),
		OwnerActor ? *OwnerActor->GetName() : TEXT("None"), Duration);
}

void UAshenConcealmentComponent::ExitConcealment()
{
	if (!bIsConcealed) return;

	bIsConcealed = false;

	if (GetWorld())
	{
		GetWorld()->GetTimerManager().ClearTimer(ConcealmentTimerHandle);
	}

	OnConcealmentStateChanged.Broadcast(false);
	UE_LOG(LogTemp, Log, TEXT("UAshenConcealmentComponent: Concealment state expired. Visibility restored."));
}
