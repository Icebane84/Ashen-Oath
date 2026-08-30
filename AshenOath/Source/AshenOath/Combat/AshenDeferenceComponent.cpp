// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenDeferenceComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenDeferenceComponent::UAshenDeferenceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAshenDeferenceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bIsDeferenceActive && CurrentLockoutRemaining > 0.0f)
	{
		CurrentLockoutRemaining -= DeltaTime;
		if (CurrentLockoutRemaining <= 0.0f)
		{
			bIsDeferenceActive = false;
			CurrentLockoutRemaining = 0.0f;
		}
	}
}

void UAshenDeferenceComponent::ExecuteCalculatedDeference(EDeferenceTarget Target)
{
	bIsDeferenceActive = true;
	CurrentLockoutRemaining = DeferenceLockoutSeconds;
	ActiveTarget = Target;

	if (OnCalculatedDeferenceEngaged.IsBound())
	{
		OnCalculatedDeferenceEngaged.Broadcast(Target, DeferenceLockoutSeconds);
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenDeferenceComponent: Calculated Deference engaged on target %d (0.60s lockout, 80%% poise strain absorption)."), (int32)Target);
}

void UAshenDeferenceComponent::OnCompanionStrikeDelivered()
{
	bIsDeferenceActive = false;
	CurrentLockoutRemaining = 0.0f;

	// Commit state reconciliation to SSoT Soul Publisher
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulPublisher* Publisher = GI->GetSubsystem<UAshenSoulPublisher>())
			{
				FSoulStateVector Delta;
				Delta.IntegrationDebt = -0.15f;    // Relieves unprocessed trauma
				Delta.Isolation       = -0.10f;    // Calms neuro-spiritual isolation
				Delta.GarrettTrust    = +0.25f;    // Reinforces Garrett cohesion
				Delta.SerafinaTrust   = +0.25f;    // Reinforces Serafina cohesion
				Delta.Corruption      = -0.05f;    // Thermal cleansing clears soot
				Delta.Resolve         = +0.10f;    // Restores willpower grounding

				Publisher->CommitState(Delta);

				UE_LOG(LogTemp, Log, TEXT("UAshenDeferenceComponent: Companion strike delivered. Committed state delta (Debt -0.15, Trust +0.25)."));
			}
		}
	}

	if (OnDeferenceCompanionStrikeDelivered.IsBound())
	{
		OnDeferenceCompanionStrikeDelivered.Broadcast(ActiveTarget);
	}
}
