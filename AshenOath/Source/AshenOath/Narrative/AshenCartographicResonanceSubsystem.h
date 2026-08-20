// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenCartographicResonanceSubsystem.generated.h"

/**
 * UAshenCartographicResonanceSubsystem
 * GameInstance Subsystem managing discovered map regions, parchment ink revelation coordinates, memory pins, and active journal pages.
 */
UCLASS()
class ASHENOATH_API UAshenCartographicResonanceSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	TArray<FJournalMapPin> ActiveMapPins;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	TMap<FName, FCartographicRegionData> DiscoveredRegions;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	bool RegisterMapPin(const FJournalMapPin& NewPin);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	void UpdateRegionInking(FName RegionName, float DeltaExploration);
};
