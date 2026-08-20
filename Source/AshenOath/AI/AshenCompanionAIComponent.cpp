// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenCompanionAIComponent.h"
#include "AshenOath_GameEventSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

UAshenCompanionAIComponent::UAshenCompanionAIComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	CurrentAIState = EAshenCompanionAIState::OffensiveSupport;
	bSymbioticResonanceActive = false;
	ResonanceDuration = 8.0f;
	ResonanceTimer = 0.0f;
}

void UAshenCompanionAIComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCompanionAIComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bSymbioticResonanceActive)
	{
		ResonanceTimer -= DeltaTime;
		if (ResonanceTimer <= 0.0f)
		{
			DeactivateSymbioticResonance();
		}
	}

	UpdateAIStateMachine(DeltaTime);
}

void UAshenCompanionAIComponent::UpdateAIStateMachine(float DeltaTime)
{
	switch (CurrentAIState)
	{
	case EAshenCompanionAIState::TacticalTriage:
		UpdateTacticalTriage(DeltaTime);
		break;
	case EAshenCompanionAIState::UnchainedContainment:
		UpdateUnchainedContainment(DeltaTime);
		break;
	case EAshenCompanionAIState::RecoveryAnchoring:
		UpdateRecoveryAnchoring(DeltaTime);
		break;
	case EAshenCompanionAIState::OffensiveSupport:
	default:
		UpdateOffensiveSupport(DeltaTime);
		break;
	}
}

void UAshenCompanionAIComponent::TransitionToState(EAshenCompanionAIState NewState)
{
	if (CurrentAIState == NewState)
	{
		return;
	}

	EAshenCompanionAIState OldState = CurrentAIState;
	CurrentAIState = NewState;

	OnStateChanged.Broadcast(OldState, NewState);
	UE_LOG(LogTemp, Log, TEXT("Ashen Companion AI transitioning state: %d -> %d"), static_cast<int32>(OldState), static_cast<int32>(NewState));
}

float UAshenCompanionAIComponent::CalculateNyxMultiplier(float Corruption) const
{
	return 1.0f + (FMath::Exp(Corruption) - 1.0f);
}

void UAshenCompanionAIComponent::ApplyTransference(float RawDamage, float KaelenCorruption)
{
	if (bSymbioticResonanceActive || SerafinaConfig.bIsCollapsed)
	{
		return;
	}

	float NyxMultiplier = CalculateNyxMultiplier(KaelenCorruption);
	float BurnoutIncrement = RawDamage * SerafinaConfig.TransferenceCoefficient * NyxMultiplier;

	SerafinaConfig.CurrentBurnout = FMath::Clamp(SerafinaConfig.CurrentBurnout + BurnoutIncrement, 0.0f, 1.0f);

	if (SerafinaConfig.CurrentBurnout >= SerafinaConfig.CollapseThreshold)
	{
		TriggerSerafinaCollapse();
	}
	else if (SerafinaConfig.CurrentBurnout >= SerafinaConfig.LockoutThreshold)
	{
		SetSerafinaLockoutState(true);
	}
}

void UAshenCompanionAIComponent::SetSerafinaLockoutState(bool bLockedOut)
{
	if (SerafinaConfig.bIsLockedOut == bLockedOut)
	{
		return;
	}

	SerafinaConfig.bIsLockedOut = bLockedOut;
	if (bLockedOut)
	{
		OnWardenBulwarkLockedOut.Broadcast();
		UE_LOG(LogTemp, Warning, TEXT("Serafina entered Lockout State (Burnout >= 0.70). Warden's Bulwark disabled!"));
	}
}

void UAshenCompanionAIComponent::TriggerSerafinaCollapse()
{
	if (SerafinaConfig.bIsCollapsed)
	{
		return;
	}

	SerafinaConfig.bIsCollapsed = true;
	SerafinaConfig.bIsLockedOut = true;
	TransitionToState(EAshenCompanionAIState::RecoveryAnchoring);

	OnSerafinaCollapsed.Broadcast();
	UE_LOG(LogTemp, Error, TEXT("Serafina collapsed under extreme Empathic Burnout!"));
}

bool UAshenCompanionAIComponent::DeployGarrettSmokeBalm(FVector Location)
{
	if (GarrettConfig.CurrentSmokeBalms <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Garrett failed to deploy Smoke Balm: Inventory empty."));
		return false;
	}

	GarrettConfig.CurrentSmokeBalms--;
	UE_LOG(LogTemp, Log, TEXT("Garrett deployed Smoke Balm at %s. Remaining: %d"), *Location.ToString(), GarrettConfig.CurrentSmokeBalms);
	return true;
}

void UAshenCompanionAIComponent::CheckSentinelVigilInterception(float DeltaTime)
{
	if (GarrettConfig.bSentinelVigilOnCooldown)
	{
		return;
	}

	AActor* Owner = GetOwner();
	if (Owner)
	{
		// Intercept logic evaluated during unchained containment phase
	}
}

void UAshenCompanionAIComponent::ExecuteSentinelVigilInterception(AActor* KaelenActor, AActor* SerafinaActor)
{
	GarrettConfig.bSentinelVigilOnCooldown = true;
	GarrettConfig.LastVigilTime = UGameplayStatics::GetRealTimeSeconds(GetWorld());
	UE_LOG(LogTemp, Warning, TEXT("Garrett executed Sentinel's Vigil! Intercepted target-blind strike!"));
}

void UAshenCompanionAIComponent::TriggerSymbioticResonance()
{
	bSymbioticResonanceActive = true;
	ResonanceTimer = ResonanceDuration;

	OnSymbioticResonanceTriggered.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("SYMBIOTIC RESONANCE TRIGGERED! Burnout and Sickness frozen for %.1fs!"), ResonanceDuration);
}

void UAshenCompanionAIComponent::DeactivateSymbioticResonance()
{
	bSymbioticResonanceActive = false;
	ResonanceTimer = 0.0f;

	OnSymbioticResonanceExpired.Broadcast();
	UE_LOG(LogTemp, Log, TEXT("Symbiotic Resonance expired. Normal resource accumulation resumed."));
}

void UAshenCompanionAIComponent::UpdateOffensiveSupport(float DeltaTime)
{
}

void UAshenCompanionAIComponent::UpdateTacticalTriage(float DeltaTime)
{
}

void UAshenCompanionAIComponent::UpdateUnchainedContainment(float DeltaTime)
{
	CheckSentinelVigilInterception(DeltaTime);
}

void UAshenCompanionAIComponent::UpdateRecoveryAnchoring(float DeltaTime)
{
}
