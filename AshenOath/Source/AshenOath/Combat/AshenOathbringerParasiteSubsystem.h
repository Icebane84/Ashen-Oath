// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Combat/AshenParasiticBladeTypes.h"
#include "AshenOathbringerParasiteSubsystem.generated.h"

/**
 * UAshenOathbringerParasiteSubsystem
 * 
 * Central world subsystem governing Oathbringer's parasitic consciousness, corruption scaling, and Eldrin/Nyx whisper dispatches.
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerParasiteSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenOathbringerParasiteSubsystem();

	/** Sets corruption scalar and updates mass and state */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Blade")
	void SetCorruption(float Corruption01);

	/** Injects Gloomwood needle freezing corruption */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Blade")
	void ApplyGloomwoodStabilization(float DurationSeconds);

	/** Triggers an Eldrin or Nyx whisper */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Blade")
	void TriggerWhisper(const FText& WhisperText, float VolumeMultiplier);

	UFUNCTION(BlueprintPure, Category = "Ashen|Blade")
	FOathbringerParasiticVector GetBladeState() const { return BladeState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Blade")
	FOnParasiteStateChanged OnParasiteStateChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Blade")
	FOnEldrinWhisperTriggered OnEldrinWhisperTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Blade")
	FOnGloomwoodNeedleInjected OnGloomwoodNeedleInjected;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Blade")
	FOnBladeMassRecalculated OnBladeMassRecalculated;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Blade")
	FOathbringerParasiticVector BladeState;
};
