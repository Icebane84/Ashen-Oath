// Copyright Ashen Oath. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulStateVector.h" // Required for FSoulStateVector
#include "AshenUnreliableNeedleMatrixComponent.generated.h"

/**
 * @struct FDeceptiveTimingData
 * @brief A payload broadcast to UI and Audio systems, containing potentially falsified timing information.
 * This struct ensures that presentation layers are decoupled from the true game state.
 */
USTRUCT(BlueprintType)
struct FDeceptiveTimingData
{
    GENERATED_BODY()

    // The start time of the window to display to the player.
    UPROPERTY(BlueprintReadOnly, Category = "Deceptive Timing")
    float DeceptiveWindowStartTime = 0.0f;

    // The duration of the window to display to the player.
    UPROPERTY(BlueprintReadOnly, Category = "Deceptive Timing")
    float DeceptiveWindowDuration = 0.0f;

    // The current offset from reality, for driving shader/audio distortion intensity.
    UPROPERTY(BlueprintReadOnly, Category = "Deceptive Timing")
    float CurrentDeceptionOffset = 0.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDeceptiveStateUpdated, const FDeceptiveTimingData&, DeceptiveData);

/**
 * @class UAshenUnreliableNeedleMatrixComponent
 * @brief Manages the "Unreliable Needle Matrix" mechanic per ENGINE-SPEC-003.
 *
 * This component is the single source of truth for timing-based actions like parrying.
 * It subscribes to the USoulConstellationSubsystem to read the player's psychological state
 * (Corruption, IntegrationDebt) and calculates a "DeceptionOffset".
 *
 * It provides the TRUE timing window to the internal combat systems for hit validation,
 * while broadcasting a potentially DECEPTIVE timing window to the UI and audio systems.
 * This forces the player to rely on feel and instinct rather than trusting the UI when
 * Kaelen's mind is unstable.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNeedleMatrixComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UAshenUnreliableNeedleMatrixComponent();

    /** Broadcasts the deceptive timing data for UI and audio systems to visualize. */
    UPROPERTY(BlueprintAssignable, Category = "Delegates")
    FOnDeceptiveStateUpdated OnDeceptiveStateUpdated;

    /**
     * @brief Attempts to begin a new parry window.
     * @return True if the window was successfully opened, false if already active or on cooldown.
     */
    UFUNCTION(BlueprintCallable, Category = "Needle Matrix")
    bool TryBeginParryWindow();

    /**
     * @brief Checks if the provided world time falls within the TRUE, mechanically-valid parry window.
     * This is called by the HurtboxComponent upon receiving a hit to validate a successful parry.
     * @param WorldTime The current world time of the hit event.
     * @return True if the hit was successfully parried.
     */
    UFUNCTION(BlueprintPure, Category = "Needle Matrix")
    bool IsWithinTrueParryWindow(float WorldTime) const;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    /**
     * @brief Callback function bound to the Soul Constellation Kernel's delegate.
     * Updates the internal corruption state and recalculates the deception offset.
     */
    UFUNCTION()
    void OnSoulStateUpdated(const FSoulStateVector& NewState);

    /** Recalculates the deception offset based on the current psychological state. */
    void UpdateDeceptionOffset();

    /** The actual, mechanically-correct duration of the parry window in seconds. */
    UPROPERTY(EditDefaultsOnly, Category = "Needle Matrix|Tuning")
    float TrueParryWindowDuration = 0.25f;

    /** The cooldown period after a parry window closes before another can be opened. */
    UPROPERTY(EditDefaultsOnly, Category = "Needle Matrix|Tuning")
    float ParryCooldown = 0.5f;

    /** The maximum possible time offset (in seconds) for the deceptive UI. */
    UPROPERTY(EditDefaultsOnly, Category = "Needle Matrix|Deception")
    float MaxDeceptionOffset = 0.15f;

    /** The level of Corruption at which the deception mechanic begins to activate. */
    UPROPERTY(EditDefaultsOnly, Category = "Needle Matrix|Deception")
    float CorruptionActivationThreshold = 0.3f;

    /** The level of Integration Debt at which the deception mechanic begins to activate. */
    UPROPERTY(EditDefaultsOnly, Category = "Needle Matrix|Deception")
    float DebtActivationThreshold = 0.5f;

    //~ Begin Runtime State
    // These properties are transient and represent the live state of the matrix.

    /** Is a parry window currently active? */
    UPROPERTY(Transient)
    bool bIsWindowActive = false;

    /** The world time when the true parry window began. */
    UPROPERTY(Transient)
    float TrueWindowStartTime = 0.0f;

    /** The world time when the current parry cooldown will end. */
    UPROPERTY(Transient)
    float CooldownEndTime = 0.0f;

    /** The current time offset between the true window and the deceptive window. */
    UPROPERTY(Transient)
    float CurrentDeceptionOffset = 0.0f;

    /** Cached value of Kaelen's Corruption from the last kernel update. */
    UPROPERTY(Transient)
    float CachedCorruption = 0.0f;

    /** Cached value of Kaelen's Integration Debt from the last kernel update. */
    UPROPERTY(Transient)
    float CachedIntegrationDebt = 0.0f;

    /** Weak pointer to the Soul Constellation Subsystem for safe access. */
    UPROPERTY(Transient)
    TWeakObjectPtr<class UAshenSoulConstellationSubsystem> SoulConstellationSubsystem;

    /** Handle for the bound delegate to ensure clean unbinding. */
    FDelegateHandle OnStateVectorInvalidatedHandle;
    //~ End Runtime State
};