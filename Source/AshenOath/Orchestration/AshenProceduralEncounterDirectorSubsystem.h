// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenProceduralEncounterDirectorSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProceduralEncounterComposedSignature, int32, ThreatTier, int32, EnemyCount);

/**
 * UAshenProceduralEncounterDirectorSubsystem
 *
 * World Subsystem composing dynamic enemy waves based on Kaelen's current trauma/sanity level (Sophia's recommendation #2).
 */
UCLASS()
class ASHENOATH_API UAshenProceduralEncounterDirectorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ProceduralEncounter")
	void ComposeDynamicEncounter(float CurrentSanity, float IntegrationDebt);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ProceduralEncounter|Events")
	FOnProceduralEncounterComposedSignature OnEncounterComposed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ProceduralEncounter")
	int32 ActiveThreatTier = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|ProceduralEncounter")
	int32 ActiveEnemyCount = 3;
};
