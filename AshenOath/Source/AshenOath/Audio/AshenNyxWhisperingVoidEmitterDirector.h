// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenNyxWhisperingVoidEmitterDirector.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWhisperSpawnedSignature, FVector, WhisperLocation, float, HallucinationIntensity);

/**
 * UAshenNyxWhisperingVoidEmitterDirector
 *
 * Spatial audio & narrative director spawning localized hallucination whispers (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API UAshenNyxWhisperingVoidEmitterDirector : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NyxWhispers")
	void SpawnLocalizedWhisper(FVector Location, float Intensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|NyxWhispers|Events")
	FOnWhisperSpawnedSignature OnWhisperSpawned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|NyxWhispers")
	int32 TotalWhispersSpawned = 0;
};
