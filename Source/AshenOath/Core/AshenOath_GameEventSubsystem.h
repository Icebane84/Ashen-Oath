// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenOath_GameEventSubsystem.generated.h"

class ACombatEnemy;
class USoundBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDiedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnItemCollectedSignature, FName, ItemID);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCombatStateChangedSignature, bool, bInCombat);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFootstepOccurredSignature, FVector, Position, FVector, Normal);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnBossSpawnedSignature, ACombatEnemy*, BossActor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossPhaseChangedSignature, int32, PhaseIndex, float, SpeedMultiplier);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVfxRequestedSignature, FName, EffectName, FVector, Position, FRotator, Rotation);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnSpatialSoundRequestedSignature, USoundBase*, Sound, FVector, Position, float, VolumeMultiplier, float, PitchMultiplier);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnManifestationTriggeredSignature, FString, ManifestationType, float, Instability, FString, Description);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnCombatEventFiredSignature, FString, EventType, AActor*, Source, AActor*, Target, float, Magnitude);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPlayerManaChangedSignature, float, CurrentMana, float, MaxMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSanctuaryRestedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteractionHintShownSignature, const FString&, HintText);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteractionHintHiddenSignature);


/**
 * UAshenOath_GameEventSubsystem
 * Global Event Bus dispatching game-wide events to decoupled systems.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenOath_GameEventSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Event broadcast when the player character dies */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnPlayerDiedSignature OnPlayerDied;

	/** Event broadcast when an item is collected */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnItemCollectedSignature OnItemCollected;

	/** Event broadcast when combat state changes */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnCombatStateChangedSignature OnCombatStateChanged;

	/** Event broadcast when a footstep occurs */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnFootstepOccurredSignature OnFootstepOccurred;

	/** Event broadcast when a boss spawns */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnBossSpawnedSignature OnBossSpawned;

	/** Event broadcast when a boss changes phases */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnBossPhaseChangedSignature OnBossPhaseChanged;

	/** Event broadcast when a VFX is requested */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnVfxRequestedSignature OnVfxRequested;

	/** Event broadcast when a spatial sound is requested */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnSpatialSoundRequestedSignature OnSpatialSoundRequested;

	/** Event broadcast when a cognitive manifestation is triggered */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnManifestationTriggeredSignature OnManifestationTriggered;

	/** Event broadcast when a combat event (strike, parry, damage) occurs */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnCombatEventFiredSignature OnCombatEventFired;

	/** Event broadcast when the player's mana changes */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnPlayerManaChangedSignature OnPlayerManaChanged;


	/** Event broadcast when player rests at a sanctuary */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnSanctuaryRestedSignature OnSanctuaryRested;

	/** Event broadcast when an interaction HUD prompt is shown */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnInteractionHintShownSignature OnInteractionHintShown;

	/** Event broadcast when an interaction HUD prompt is hidden */
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Events")
	FOnInteractionHintHiddenSignature OnInteractionHintHidden;

	/** Helper to broadcast player death */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastPlayerDied();

	/** Helper to broadcast item collection */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastItemCollected(FName ItemID);

	/** Helper to broadcast combat state change */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastCombatStateChanged(bool bInCombat);

	/** Helper to broadcast footstep */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastFootstepOccurred(FVector Position, FVector Normal);

	/** Helper to broadcast boss spawn */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastBossSpawned(ACombatEnemy* BossActor);

	/** Helper to broadcast boss phase change */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastBossPhaseChanged(int32 PhaseIndex, float SpeedMultiplier);

	/** Helper to broadcast VFX request */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastVfxRequested(FName EffectName, FVector Position, FRotator Rotation);

	/** Helper to broadcast spatial sound request */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastSpatialSoundRequested(USoundBase* Sound, FVector Position, float VolumeMultiplier = 1.0f, float PitchMultiplier = 1.0f);

	/** Helper to broadcast cognitive manifestation events */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastManifestationTriggered(FString ManifestationType, float Instability, FString Description);

	/** Helper to broadcast combat event occurrences */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastCombatEventFired(FString EventType, AActor* Source, AActor* Target, float Magnitude);

	/** Helper to broadcast player mana changes */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastPlayerManaChanged(float CurrentMana, float MaxMana);


	/** Helper to broadcast sanctuary rested events */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastSanctuaryRested();

	/** Helper to broadcast interaction HUD prompt show */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastInteractionHintShown(const FString& HintText);

	/** Helper to broadcast interaction HUD prompt hide */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Events")
	void BroadcastInteractionHintHidden();
};
