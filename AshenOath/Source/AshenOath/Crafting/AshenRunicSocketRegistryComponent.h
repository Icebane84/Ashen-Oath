// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenRunicSocketRegistryComponent.generated.h"

/**
 * UAshenRunicSocketRegistryComponent
 * 
 * Manages the persistent socket slots attached directly to an equippable weapon actor.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRunicSocketRegistryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRunicSocketRegistryComponent();

	/** Sockets a rune into a specific slot type */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Reliquary")
	bool InstallRune(ERunicSocketType Slot, const FRunicSocketEntry& Entry);

	/** Clears a specific socket slot */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Reliquary")
	bool RemoveRune(ERunicSocketType Slot);

	UFUNCTION(BlueprintPure, Category = "Ashen|Reliquary")
	bool HasSocketedRune(ERunicSocketType Slot) const;

	UFUNCTION(BlueprintPure, Category = "Ashen|Reliquary")
	int32 GetFilledSocketCount() const { return Sockets.Num(); }

private:
	TMap<ERunicSocketType, FRunicSocketEntry> Sockets;
};
