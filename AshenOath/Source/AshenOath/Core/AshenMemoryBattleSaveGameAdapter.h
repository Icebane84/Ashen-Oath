// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMemoryBattleSaveGameAdapter.generated.h"

/**
 * UAshenMemoryBattleSaveGameAdapter
 * Serializes resolved memory battle IDs, lorekeeper beacon states, and harmony totals to persistent save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryBattleSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryBattleSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeResolvedMemoryToSave(FName EchoID, bool bVictory, float HarmonyReward);
};
