// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenLivingCodexSaveGameAdapter.generated.h"

/**
 * UAshenLivingCodexSaveGameAdapter
 * Serializes unlocked codex entry IDs, faction completion stats, and read status arrays to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLivingCodexSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLivingCodexSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveCodexArchive(int32 TotalUnlocked, int32 TotalRead);
};
