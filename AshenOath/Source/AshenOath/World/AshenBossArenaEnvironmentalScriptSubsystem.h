// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenBossArenaEnvironmentalScriptSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossArenaStateChangedSignature, FName, ArenaID, int32, PhaseIndex);

/**
 * UAshenBossArenaEnvironmentalScriptSubsystem
 *
 * World Subsystem modulating arena boundaries, environmental hazards, and camera tension during boss encounters.
 */
UCLASS()
class ASHENOATH_API UAshenBossArenaEnvironmentalScriptSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|BossArena")
	void TriggerArenaPhaseScript(FName ArenaID, int32 PhaseIndex);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BossArena|Events")
	FOnBossArenaStateChangedSignature OnArenaStateChanged;
};
