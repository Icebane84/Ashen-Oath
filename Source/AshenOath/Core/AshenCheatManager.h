// AshenCheatManager.h
// Copyright Ashen Oath. All rights reserved.
// Dedicated developer Cheat Manager extending UCheatManager for live playtesting and tuning.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CheatManager.h"
#include "AshenCheatManager.generated.h"

/**
 * @class UAshenCheatManager
 * @brief Console cheat manager for live state vector, debt, despair, and death testing.
 */
UCLASS()
class ASHENOATH_API UAshenCheatManager : public UCheatManager
{
	GENERATED_BODY()

public:
	/** Kills the player immediately to test the Soulslike death & echo retrieval pipeline. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void KillPlayer();

	/** Rest at nearest Heartstone sanctuary checkpoint on demand. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void RestSanctuary();

	/** Sets Kaelen's Resolve float (0.0 to 1.0) and recompiles state. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void SetResolve(float Value);

	/** Sets Kaelen's Corruption float (0.0 to 1.0) and recompiles state. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void SetCorruption(float Value);

	/** Sets Kaelen's Isolation float (0.0 to 1.0) and recompiles state. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void SetIsolation(float Value);

	/** Sets Garrett's Trust float (0.0 to 1.0). */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void SetGarrettTrust(float Value);

	/** Sets Serafina's Trust float (0.0 to 1.0). */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void SetSerafinaTrust(float Value);

	/** Sets global Despair accumulator (0.0 to 1.0). */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void SetDespair(float Value);

	/** Advance a campaign Vigil by VigilID. */
	UFUNCTION(Exec, Category = "AshenOath|Cheats")
	void ProgressVigil(FString VigilID);
};
