// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNightmareSaveGameAdapter.generated.h"

/**
 * UAshenNightmareSaveGameAdapter
 * Serializes sealed rift counts, historical nightmare survival times, and highest strain level reached to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNightmareSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNightmareSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveNightmareProgress(int32 TotalSealedRifts, float MaxIncursionIntensitySurvived);
};
