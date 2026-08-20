// Copyright Phoenix Protocol. All rights reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_NPCReactivityComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnReactivityStateChangedSignature, float, FearLevel, float, TrustLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCompanionVulnerabilityChangedSignature, bool, bIsVulnerable);

UENUM(BlueprintType)
enum class EAshenNPCReactivityState : uint8
{
	Calm,
	Uncomfortable,
	Terrified,
	Hostile
};


/**
 * UAshenOath_NPCReactivityComponent
 * Evaluates companion NPC fear and trust ratings dynamically based on Kaelen's
 * mental instability, shadow manifestations, and physical proximity.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_NPCReactivityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_NPCReactivityComponent();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure, Category = "AshenOath|NPC")
	EAshenNPCReactivityState GetCurrentReactivityState() const { return CurrentState; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|NPC")
	float GetCurrentFearLevel() const { return CurrentFearLevel; }

	/** Returns pathfinding spatial offset driven by active BehavioralProfile (e.g. Garrett isolated 800uu, Serafina burned out 550uu). */
	UFUNCTION(BlueprintPure, Category = "AshenOath|NPC")
	float GetPathfindingOffset() const;

	/** Returns navigation response delay in seconds (0.2s when Integration Debt is at RuntimeNoise stage). */
	UFUNCTION(BlueprintPure, Category = "AshenOath|NPC")
	float GetNavigationResponseDelay() const;

	/** Add fatigue to accumulator (called on combat events received). */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|NPC|Fatigue")
	void AddFatigue(float Amount);

	/** Clear fatigue accumulator back to 0. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|NPC|Fatigue")
	void ClearFatigue();

	/** Returns current fatigue rating (0.0 to 1.0). */
	UFUNCTION(BlueprintPure, Category = "AshenOath|NPC|Fatigue")
	float GetFatigueAccumulator() const { return FatigueAccumulator; }

	/** Returns true when FatigueAccumulator > 0.7 (companion vulnerable). */
	UFUNCTION(BlueprintPure, Category = "AshenOath|NPC|Fatigue")
	bool IsVulnerable() const { return bIsVulnerable; }


protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|NPC")
	float ProximityCheckRadius;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|NPC")
	float BaseTrustRating;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|NPC|Events")
	FOnReactivityStateChangedSignature OnReactivityStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|NPC|Events")
	FOnCompanionVulnerabilityChangedSignature OnVulnerabilityChanged;

private:
	UFUNCTION()
	void HandleManifestationTriggered(FString ManifestationType, float Instability, FString Description);

	UFUNCTION()
	void HandleCombatEventFired(FString EventType, AActor* Source, AActor* Target, float Magnitude);

	void EvaluatePlayerProximityAndCorruption(float DeltaTime);
	void UpdateFatigueRecovery(float DeltaTime);


private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|NPC")
	EAshenNPCReactivityState CurrentState;

	UPROPERTY(VisibleAnywhere, Category = "AshenOath|NPC")
	float CurrentFearLevel;

	UPROPERTY(VisibleAnywhere, Category = "AshenOath|NPC|Fatigue")
	float FatigueAccumulator = 0.0f;

	UPROPERTY(VisibleAnywhere, Category = "AshenOath|NPC|Fatigue")
	bool bIsVulnerable = false;

	float TimeSinceLastCombatEvent = 0.0f;

	TWeakObjectPtr<APawn> CachedPlayerPawn;
};

