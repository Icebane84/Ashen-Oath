// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenShadowfenEncounterDirectorSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShadowfenEncounterSpawnedSignature, FName, EncounterID, int32, ThreatLevel);

/**
 * UAshenShadowfenEncounterDirectorSubsystem
 *
 * World Subsystem orchestrating dynamic encounters in Shadowfen darklands.
 */
UCLASS()
class ASHENOATH_API UAshenShadowfenEncounterDirectorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ShadowfenDirector")
	void DispatchShadowfenEncounter(FName EncounterID, int32 ThreatLevel = 1);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ShadowfenDirector|Events")
	FOnShadowfenEncounterSpawnedSignature OnEncounterSpawned;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ShadowfenDirector")
	int32 TotalEncountersDispatched = 0;
};
