// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSoulConstellationPurificationLocusActor.generated.h"

/**
 * AAshenSoulConstellationPurificationLocusActor
 * World locus actor driving radiant white flame pillar VFX during rituals.
 */
UCLASS()
class ASHENOATH_API AAshenSoulConstellationPurificationLocusActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSoulConstellationPurificationLocusActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void IgnitePurificationFlamePillar();
};
