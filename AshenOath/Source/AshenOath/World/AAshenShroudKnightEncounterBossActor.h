// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AAshenShroudKnightEncounterBossActor.generated.h"

/**
 * AAshenShroudKnightEncounterBossActor
 * 
 * Spatial 2.1-meter encounter boss character actor with 5 socketed visor eyes, cloth shroud cards, and dynamic Nyx bile weeping.
 */
UCLASS()
class ASHENOATH_API AAshenShroudKnightEncounterBossActor : public ACharacter
{
	GENERATED_BODY()

public:
	AAshenShroudKnightEncounterBossActor();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Ashen|Boss")
	float GetBossHeightMeters() const { return BossHeightMeters; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|Boss")
	float BossHeightMeters = 2.1f;
};
