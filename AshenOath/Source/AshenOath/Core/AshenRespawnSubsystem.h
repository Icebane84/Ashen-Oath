// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenRespawnSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPlayerRespawnedSignature, FVector, RespawnLocation);

/**
 * UAshenRespawnSubsystem
 *
 * Manages player death and respawn at the last visited sanctuary.
 * Tracks the active sanctuary respawn point and triggers respawn
 * with a 1.5-second screen-fade delay.
 */
UCLASS()
class ASHENOATH_API UAshenRespawnSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Respawn")
	void RegisterSanctuaryLocation(FVector SanctuaryLocation);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Respawn")
	void TriggerPlayerDeath(APawn* DeadPawn);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Respawn")
	FVector GetActiveSanctuaryLocation() const { return ActiveSanctuaryLocation; }

	// --- State ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Respawn")
	FVector ActiveSanctuaryLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Respawn")
	float RespawnFadeDelay = 1.5f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Respawn|Events")
	FOnPlayerRespawnedSignature OnPlayerRespawned;

private:
	FTimerHandle RespawnTimerHandle;
	TWeakObjectPtr<APawn> PendingRespawnPawn;

	void ExecuteRespawn();
};
