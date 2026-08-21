// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Tactics/AshenSquadTacticalTypes.h"
#include "AshenSquadTacticalSubsystem.generated.h"

/**
 * UAshenSquadTacticalSubsystem
 * 
 * Central world subsystem coordinating tactical command wheel invocation,
 * temporal bullet-time dilation (0.20x), and companion order dispatch.
 */
UCLASS()
class ASHENOATH_API UAshenSquadTacticalSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenSquadTacticalSubsystem();

	/** Toggles the radial tactical command wheel */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Tactics")
	void SetTacticalWheelOpen(bool bOpen);

	/** Dispatches a squad command to a companion */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Tactics")
	bool DispatchSquadCommand(const FSquadCommandEntry& Command);

	UFUNCTION(BlueprintPure, Category = "Ashen|Tactics")
	bool IsWheelOpen() const { return bWheelOpen; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Tactics")
	ETemporalDilationState GetCurrentDilationState() const { return DilationState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Tactics")
	FOnSquadCommandDispatched OnSquadCommandDispatched;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Tactics")
	FOnTemporalDilationChanged OnTemporalDilationChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Tactics")
	FOnTacticalWheelVisibilityChanged OnTacticalWheelVisibilityChanged;

private:
	bool bWheelOpen = false;
	ETemporalDilationState DilationState = ETemporalDilationState::Realtime;
};
