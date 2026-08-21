// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Crafting/AshenRunicReliquaryTypes.h"
#include "AshenSoulForgeTransmuterComponent.generated.h"

/**
 * UAshenSoulForgeTransmuterComponent
 * 
 * Handles transmutation rituals converting boss Nightsteel shards and trauma
 * memories into socketable runic relics.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulForgeTransmuterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulForgeTransmuterComponent();

	/** Transmutes a boss core into a Master-Forged Blade Core rune */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Reliquary")
	FRunicSocketEntry TransmuteBossShard(const FName& BossName, float ShardPower);

	/** Transmutes emotional integration debt into a Resonant Hilt Relic */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Reliquary")
	FRunicSocketEntry TransmuteTraumaMemory(const FName& CompanionName, float IntegrationDebt);
};
