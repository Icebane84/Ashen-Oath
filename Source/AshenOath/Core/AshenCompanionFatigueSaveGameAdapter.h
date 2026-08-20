// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionFatigueSaveGameAdapter.generated.h"

/**
 * UAshenCompanionFatigueSaveGameAdapter
 * Serializes companion fatigue levels and resonance sync milestone history to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionFatigueSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionFatigueSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveCompanionFatigueStates(float GarrettFatigue, float SerafinaFatigue, float KaelenFatigue);
};
