// Copyright Ashen Oath. All rights reserved.

#include "AshenUnreliableNeedleMatrixComponent.h"
#include "AshenSoulConstellationSubsystem.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenUnreliableNeedleMatrixComponent::UAshenUnreliableNeedleMatrixComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false; // Only tick when a window is active.
}

void UAshenUnreliableNeedleMatrixComponent::BeginPlay()
{
	Super::BeginPlay();

	// Safely get the game instance and the required subsystem.
	if (UWorld* World = GetWorld())
	{
		if (UGameInstance* GameInstance = World->GetGameInstance())
		{
			if (UAshenSoulConstellationSubsystem* Subsystem = GameInstance->GetSubsystem<UAshenSoulConstellationSubsystem>())
			{
				SoulConstellationSubsystem = Subsystem;
				// Bind our update function to the kernel's delegate.
				Subsystem->OnStateVectorInvalidated.AddDynamic(this, &UAshenUnreliableNeedleMatrixComponent::OnSoulStateUpdated);

				// Perform an initial state sync.
				OnSoulStateUpdated(Subsystem->GetStateVector());
			}
		}
	}
}

void UAshenUnreliableNeedleMatrixComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	// Clean up delegate bindings to prevent dangling pointers.
	if (SoulConstellationSubsystem.IsValid())
	{
		SoulConstellationSubsystem->OnStateVectorInvalidated.RemoveDynamic(this, &UAshenUnreliableNeedleMatrixComponent::OnSoulStateUpdated);
	}
	OnStateVectorInvalidatedHandle.Reset();

	Super::EndPlay(EndPlayReason);
}

void UAshenUnreliableNeedleMatrixComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	const float CurrentWorldTime = GetWorld()->GetTimeSeconds();

	// If the window is active, check if it should be closed.
	if (bIsWindowActive && CurrentWorldTime >= (TrueWindowStartTime + TrueParryWindowDuration))
	{
		bIsWindowActive = false;
		CooldownEndTime = CurrentWorldTime + ParryCooldown;
		SetComponentTickEnabled(false); // Stop ticking to save performance.
	}
}

bool UAshenUnreliableNeedleMatrixComponent::TryBeginParryWindow()
{
	const float CurrentWorldTime = GetWorld()->GetTimeSeconds();

	// Fail if a window is already active or if we are on cooldown.
	if (bIsWindowActive || CurrentWorldTime < CooldownEndTime)
	{
		return false;
	}

	bIsWindowActive = true;
	TrueWindowStartTime = CurrentWorldTime;

	// Recalculate the deception just in case the state changed without a broadcast.
	UpdateDeceptionOffset();

	// Prepare the deceptive data payload for the UI and audio systems.
	FDeceptiveTimingData DeceptiveData;
	DeceptiveData.DeceptiveWindowStartTime = TrueWindowStartTime + CurrentDeceptionOffset;
	DeceptiveData.DeceptiveWindowDuration = TrueParryWindowDuration; // Duration is not deceptive, only the start time.
	DeceptiveData.CurrentDeceptionOffset = CurrentDeceptionOffset;

	// Broadcast the potentially false information.
	OnDeceptiveStateUpdated.Broadcast(DeceptiveData);

	// Start ticking to monitor the window's duration.
	SetComponentTickEnabled(true);

	return true;
}

bool UAshenUnreliableNeedleMatrixComponent::IsWithinTrueParryWindow(float WorldTime) const
{
	// The core validation logic. This checks against the REAL window, ignoring any deception.
	if (!bIsWindowActive)
	{
		return false;
	}

	return (WorldTime >= TrueWindowStartTime) && (WorldTime <= (TrueWindowStartTime + TrueParryWindowDuration));
}

void UAshenUnreliableNeedleMatrixComponent::OnSoulStateUpdated(const FSoulStateVector& NewState)
{
	// Cache the relevant psychological state values.
	CachedCorruption = NewState.Corruption;
	CachedIntegrationDebt = NewState.IntegrationDebt;

	// Recalculate the deception offset with the new data.
	UpdateDeceptionOffset();
}

void UAshenUnreliableNeedleMatrixComponent::UpdateDeceptionOffset()
{
	// If Kaelen's mind is clear, there is no deception.
	if (CachedCorruption < CorruptionActivationThreshold && CachedIntegrationDebt < DebtActivationThreshold)
	{
		CurrentDeceptionOffset = 0.0f;
		return;
	}

	// --- Calculate Deception Magnitude ---
	// The deception is driven by the *stronger* of the two negative psychological pressures.
	// We normalize the value based on how far it is past its activation threshold.
	
	const float CorruptionFactor = FMath::GetMappedRangeValueClamped(
		FVector2D(CorruptionActivationThreshold, 1.0f),
		FVector2D(0.0f, 1.0f),
		CachedCorruption
	);

	const float DebtFactor = FMath::GetMappedRangeValueClamped(
		FVector2D(DebtActivationThreshold, 1.0f),
		FVector2D(0.0f, 1.0f),
		CachedIntegrationDebt
	);

	// The final deception strength is the max of the two factors.
	const float DeceptionMagnitude = FMath::Max(CorruptionFactor, DebtFactor);

	// --- Calculate Deception Direction ---
	// To make it truly unreliable, the offset can be either early or late.
	// We can use a simple deterministic but chaotic function based on world time
	// to decide the direction, making it feel random but be repeatable.
	const float TimeSeed = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
	const float Sign = FMath::Sin(TimeSeed * 10.0f) > 0.0f ? 1.0f : -1.0f;

	// The final offset is the magnitude scaled by the max offset, with a shifting direction.
	CurrentDeceptionOffset = DeceptionMagnitude * MaxDeceptionOffset * Sign;
}
