// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossMemoryDuelSaveGameAdapter.generated.h"

/**
 * UAshenBossMemoryDuelSaveGameAdapter
 * Serializes boss defeat state and memory echo fragments claimed.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossMemoryDuelSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossMemoryDuelSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeBossDefeatToSave(FName BossID, bool bDefeated, int32 MemoryFragmentsGained);
};
