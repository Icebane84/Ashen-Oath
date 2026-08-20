// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenVFXPoolSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnVFXSpawnedFromPoolSignature, FName, EffectName, FVector, Location, FRotator, Rotation);

/**
 * UAshenVFXPoolSubsystem
 *
 * World subsystem pooling particle visual effects (Holy Light Aegis, Smoke Balm Cloud,
 * Bone Spur Impact Dust, Whispering Wind Swirl) to eliminate runtime allocation hitches.
 */
UCLASS()
class ASHENOATH_API UAshenVFXPoolSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// --- Public API ---
	UFUNCTION(BlueprintCallable, Category = "AshenOath|VFX")
	void SpawnPooledVFX(FName EffectName, FVector Location, FRotator Rotation);

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VFX|Events")
	FOnVFXSpawnedFromPoolSignature OnVFXSpawnedFromPool;

private:
	TMap<FName, int32> ActivePoolCounts;
};
