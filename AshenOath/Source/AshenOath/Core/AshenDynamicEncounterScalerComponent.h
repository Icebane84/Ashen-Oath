// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDynamicEncounterScalerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEncounterScaledSignature, float, DifficultyMultiplier, int32, BonusEliteCount);

/**
 * UAshenDynamicEncounterScalerComponent
 *
 * Dynamic combat scaling component adjusting enemy density and elite spawns based on player combat efficiency & Sanity.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDynamicEncounterScalerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDynamicEncounterScalerComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|EncounterScaler")
	void ScaleEncounterDifficulty(float CombatEfficiencyRating, float PlayerSanity);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EncounterScaler|Events")
	FOnEncounterScaledSignature OnEncounterScaled;
};
