// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenNightmareLabyrinthBossSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNightmareBossDefeatedSignature, FName, BossID, bool, bTraumaConquered);

/**
 * UAshenNightmareLabyrinthBossSubsystem
 *
 * World Subsystem managing climax boss encounters inside Mindscape Nightmare Labyrinths.
 */
UCLASS()
class ASHENOATH_API UAshenNightmareLabyrinthBossSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NightmareBoss")
	void DefeatNightmareBoss(FName BossID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|NightmareBoss|Events")
	FOnNightmareBossDefeatedSignature OnNightmareBossDefeated;
};
