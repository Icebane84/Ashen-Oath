// Copyright Phoenix Protocol. All rights reserved.
#include "AshenOath_NPCReactivityComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "AshenOath_DirectorSubsystem.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_SanityComponent.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Actor.h"


UAshenOath_NPCReactivityComponent::UAshenOath_NPCReactivityComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	ProximityCheckRadius = 600.0f;
	BaseTrustRating = 100.0f;
	CurrentFearLevel = 0.0f;
	CurrentState = EAshenNPCReactivityState::Calm;
}

void UAshenOath_NPCReactivityComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenOath_GameEventSubsystem* EventBus = GI->GetSubsystem<UAshenOath_GameEventSubsystem>())
			{
				EventBus->OnManifestationTriggered.AddDynamic(this, &UAshenOath_NPCReactivityComponent::HandleManifestationTriggered);
				EventBus->OnCombatEventFired.AddDynamic(this, &UAshenOath_NPCReactivityComponent::HandleCombatEventFired);
			}

			if (UAshenOath_DirectorSubsystem* Director = GI->GetSubsystem<UAshenOath_DirectorSubsystem>())
			{
				CachedPlayerPawn = Director->GetPlayerPawn();
			}
		}
	}
}

void UAshenOath_NPCReactivityComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	EvaluatePlayerProximityAndCorruption(DeltaTime);
	UpdateFatigueRecovery(DeltaTime);
}


void UAshenOath_NPCReactivityComponent::HandleManifestationTriggered(FString ManifestationType, float Instability, FString Description)
{
	// Psychological spikes in the environment immediately raise local NPC tension
	if (Instability > 50.0f)
	{
		CurrentFearLevel = FMath::Clamp(CurrentFearLevel + (Instability * 0.15f), 0.0f, 100.0f);
	}
}

void UAshenOath_NPCReactivityComponent::EvaluatePlayerProximityAndCorruption(float DeltaTime)
{
	if (!CachedPlayerPawn.IsValid())
	{
		if (UWorld* World = GetWorld())
		{
			if (UGameInstance* GI = World->GetGameInstance())
			{
				if (UAshenOath_DirectorSubsystem* Director = GI->GetSubsystem<UAshenOath_DirectorSubsystem>())
				{
					CachedPlayerPawn = Director->GetPlayerPawn();
				}
			}
		}
	}

	APawn* Player = CachedPlayerPawn.Get();
	if (!Player) return;

	const float Distance = FVector::Dist(GetOwner()->GetActorLocation(), Player->GetActorLocation());

	if (Distance > ProximityCheckRadius)
	{
		// Gradually recover calm state when player moves away
		CurrentFearLevel = FMath::FInterpTo(CurrentFearLevel, 0.0f, DeltaTime, 0.5f);
	}
	else
	{
		float Instability = 0.0f;
		if (Player->Implements<UAshenCharacterInterface>())
		{
			if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(Player))
			{
				Instability = 100.0f - Sanity->GetCurrentSanity();
			}
		}

		// Fear builds faster when close to a high-instability player
		const float DistanceWeight = 1.0f - (Distance / ProximityCheckRadius);
		const float TargetFear = Instability * DistanceWeight;

		CurrentFearLevel = FMath::FInterpTo(CurrentFearLevel, TargetFear, DeltaTime, 1.5f);
	}

	// State machine transition evaluation
	EAshenNPCReactivityState NewState = EAshenNPCReactivityState::Calm;
	if (CurrentFearLevel >= 75.0f)
	{
		NewState = EAshenNPCReactivityState::Terrified;
	}
	else if (CurrentFearLevel >= 35.0f)
	{
		NewState = EAshenNPCReactivityState::Uncomfortable;
	}

	if (NewState != CurrentState)
	{
		CurrentState = NewState;
		OnReactivityStateChanged.Broadcast(CurrentFearLevel, BaseTrustRating - CurrentFearLevel);
	}
}

float UAshenOath_NPCReactivityComponent::GetPathfindingOffset() const
{
	float BaseOffset = 200.0f; // Default baseline proximity offset

	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				const FBehavioralProfile& Profile = Kernel->GetActiveProfile();

				// Garrett isolated offset
				if (Profile.Tactical == ETacticalProfile::Cynical_Isolated)
				{
					BaseOffset = 800.0f;
				}
				// Serafina burned out offset
				else if (Profile.Empathic == EEmpathicProfile::Burned_Out)
				{
					BaseOffset = 550.0f;
				}
			}
		}
	}

	return BaseOffset;
}

float UAshenOath_NPCReactivityComponent::GetNavigationResponseDelay() const
{
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				// ENGINE-SPEC-001 Section 2: Runtime Noise adds 200ms pathfinding delay
				if (Kernel->GetDebtStage() == EAshenIntegrationDebtStage::RuntimeNoise || Kernel->GetDebtStage() == EAshenIntegrationDebtStage::ForcedCollapse)
				{
					return 0.2f;
				}
			}
		}
	}

	return 0.0f;
}

void UAshenOath_NPCReactivityComponent::AddFatigue(float Amount)
{
	if (Amount <= 0.0f) return;

	FatigueAccumulator = FMath::Clamp(FatigueAccumulator + Amount, 0.0f, 1.0f);
	TimeSinceLastCombatEvent = 0.0f;

	const bool bNewVulnerable = (FatigueAccumulator >= 0.7f);
	if (bNewVulnerable != bIsVulnerable)
	{
		bIsVulnerable = bNewVulnerable;
		UE_LOG(LogTemp, Log, TEXT("Companion Vulnerability changed: %s (Fatigue: %.2f)"),
			bIsVulnerable ? TEXT("VULNERABLE") : TEXT("Normal"), FatigueAccumulator);
		OnVulnerabilityChanged.Broadcast(bIsVulnerable);
	}
}

void UAshenOath_NPCReactivityComponent::ClearFatigue()
{
	FatigueAccumulator = 0.0f;
	TimeSinceLastCombatEvent = 0.0f;
	if (bIsVulnerable)
	{
		bIsVulnerable = false;
		OnVulnerabilityChanged.Broadcast(false);
	}
}

void UAshenOath_NPCReactivityComponent::HandleCombatEventFired(FString EventType, AActor* Source, AActor* Target, float Magnitude)
{
	// Accumulate fatigue when owner is involved in combat events
	if (Target == GetOwner() || Source == GetOwner())
	{
		AddFatigue(0.08f * (Magnitude > 0.0f ? Magnitude / 100.0f : 1.0f));
	}
}

void UAshenOath_NPCReactivityComponent::UpdateFatigueRecovery(float DeltaTime)
{
	TimeSinceLastCombatEvent += DeltaTime;

	// WITNESS phase: recover fatigue slowly when no combat events for 45+ seconds
	if (TimeSinceLastCombatEvent >= 45.0f && FatigueAccumulator > 0.0f)
	{
		FatigueAccumulator = FMath::Clamp(FatigueAccumulator - (0.015f * DeltaTime), 0.0f, 1.0f);
		if (bIsVulnerable && FatigueAccumulator < 0.5f)
		{
			bIsVulnerable = false;
			OnVulnerabilityChanged.Broadcast(false);
		}
	}
}


