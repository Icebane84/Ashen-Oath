// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenRegionalCorruptionSpreadSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnRegionalCorruptionUpdated, int32, SectorIndex, float, NewCorruptionLevel);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnZoneCorruptionChangedSignature, FName, ZoneID, float, NewCorruptionLevel);

/**
 * UAshenRegionalCorruptionSpreadSubsystem
 * 64-sector regional world corruption simulation affecting enemy aggression, weather, and trade.
 */
UCLASS()
class ASHENOATH_API UAshenRegionalCorruptionSpreadSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Regional Corruption")
	FOnRegionalCorruptionUpdated OnRegionalCorruptionUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Regional Corruption")
	FOnZoneCorruptionChangedSignature OnZoneCorruptionChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Regional Corruption")
	TArray<float> SectorCorruptionLevels;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Regional Corruption")
	TMap<FName, float> ZoneCorruptionMap;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Regional Corruption")
	void PropagateRegionalCorruption(int32 SourceSector, float Intensity);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Regional Corruption")
	float GetSectorCorruption(int32 SectorIndex) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Regional Corruption")
	void AdvanceZoneCorruption(FName ZoneID, float DeltaAmount);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath | Regional Corruption")
	float GetZoneCorruptionLevel(FName ZoneID) const;
};
