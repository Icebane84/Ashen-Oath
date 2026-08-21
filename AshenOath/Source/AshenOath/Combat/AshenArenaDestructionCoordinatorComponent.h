// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossArenaTypes.h"
#include "AshenArenaDestructionCoordinatorComponent.generated.h"

/**
 * UAshenArenaDestructionCoordinatorComponent
 * 
 * Manages dynamic Chaos environmental destruction, tracking intact pillars
 * and arena debris obstruction.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenArenaDestructionCoordinatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenArenaDestructionCoordinatorComponent();

	/** Sunders a pillar and returns updated obstruction scalar */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Boss|Chaos")
	float SunderPillar(int32 PillarIndex);

	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Chaos")
	int32 GetIntactPillarsCount() const { return IntactPillars; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Boss|Chaos")
	float GetObstructionScalar() const { return ObstructionScalar; }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Boss|Chaos")
	int32 TotalPillars = 4;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Boss|Chaos")
	int32 IntactPillars = 4;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|Boss|Chaos")
	float ObstructionScalar = 0.0f;
};
