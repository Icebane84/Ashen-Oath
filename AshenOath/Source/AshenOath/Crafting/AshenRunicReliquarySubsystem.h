// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicReliquarySubsystem.generated.h"

/**
 * UAshenRunicReliquarySubsystem
 * 
 * Central world subsystem managing runic catalogs, boss core inventory,
 * and soul-forged weapon attunements.
 */
UCLASS()
class ASHENOATH_API UAshenRunicReliquarySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenRunicReliquarySubsystem();

	/** Registers an acquired boss core or memory rune */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Reliquary")
	void RegisterAcquiredRune(const FRunicSocketEntry& RuneEntry);

	/** Sockets a rune into a target weapon slot */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Reliquary")
	bool SocketRune(const FName& WeaponId, const FRunicSocketEntry& RuneEntry);

	/** Retrieves the active soul forge weapon state */
	UFUNCTION(BlueprintPure, Category = "Ashen|Reliquary")
	FSoulForgeWeaponState GetWeaponState(const FName& WeaponId) const;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Reliquary")
	FOnRuneSocketed OnRuneSocketed;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Reliquary")
	FOnWeaponAttunementUpdated OnWeaponAttunementUpdated;

private:
	TMap<FName, FRunicSocketEntry> AcquiredRunes;
	TMap<FName, FSoulForgeWeaponState> WeaponStates;
};
