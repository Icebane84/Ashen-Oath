// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenCombatStanceTypes.h"
#include "AshenCombatStanceSaveGameAdapter.generated.h"

/**
 * UAshenCombatStanceSaveGameAdapter
 * Serializes unlocked stance techniques, stance masteries, and flank execution statistics to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCombatStanceSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCombatStanceSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveCombatStanceMastery(ECombatStance Stance, int32 MasteryLevel, int32 FlankExecutions);
};
