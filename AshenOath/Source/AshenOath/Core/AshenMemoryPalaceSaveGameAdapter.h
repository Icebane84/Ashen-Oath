// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Memory/AshenMemoryPalaceGraphTypes.h"
#include "AshenMemoryPalaceSaveGameAdapter.generated.h"

/**
 * UAshenMemoryPalaceSaveGameAdapter
 * Serializes the complete Memory Palace node graph, unsealed loci list, and reconstructed bridges to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryPalaceSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryPalaceSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveMemoryPalaceGraphState(const TArray<FName>& UnsealedNodeIDs, int32 TotalBridgesReconstructed);
};
