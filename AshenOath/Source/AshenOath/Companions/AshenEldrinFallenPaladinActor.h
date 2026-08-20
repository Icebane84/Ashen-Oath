// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenEldrinFallenPaladinActor.generated.h"

/**
 * AAshenEldrinFallenPaladinActor
 * Psychic projection manifestation actor in Oathbringer's Inner World representing Eldrin, the Fallen Paladin.
 */
UCLASS()
class ASHENOATH_API AAshenEldrinFallenPaladinActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenEldrinFallenPaladinActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Inner World")
	float CorruptedPaladinAuraIntensity = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Inner World")
	bool ManifestEldrinGraceProjection();
};
