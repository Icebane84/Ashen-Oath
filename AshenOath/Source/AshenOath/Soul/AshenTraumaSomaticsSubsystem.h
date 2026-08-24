// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenTraumaSomaticsTypes.h"
#include "AshenTraumaSomaticsSubsystem.generated.h"

/**
 * UAshenTraumaSomaticsSubsystem
 * 
 * Central subsystem governing procedural vein corruption, dynamic blade soot accumulation, and bio-acoustic heart rate sync.
 */
UCLASS()
class ASHENOATH_API UAshenTraumaSomaticsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenTraumaSomaticsSubsystem();

	/** Updates the global somatic state from runtime debt and combat stress */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Somatics")
	void UpdateSomaticState(float IntegrationDebt, float ShadowBurnout, float StrikeJoules, bool bInActiveCombat);

	/** Cleans the Oathbringer blade at camp, restoring polish */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Somatics")
	void CleanBladeAtCampfire();

	UFUNCTION(BlueprintPure, Category = "Ashen|Somatics")
	FTraumaSomaticStateVector GetCurrentSomaticState() const { return CurrentState; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Somatics")
	FOnSomaticStageChanged OnSomaticStageChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Somatics")
	FOnBladeSootUpdated OnBladeSootUpdated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Somatics")
	FOnHeartRateShifted OnHeartRateShifted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Somatics")
	FOnBladeCleanedAtCampfire OnBladeCleanedAtCampfire;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|Somatics")
	FTraumaSomaticStateVector CurrentState;
};
