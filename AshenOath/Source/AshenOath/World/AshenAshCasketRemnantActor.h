// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenAshCasketRemnantActor.generated.h"

/**
 * AAshenAshCasketRemnantActor
 * 3D world remnant actor left behind after defeating the Ash-Casket via Cryo-Quench, allowing harvesting of frozen basalt shards.
 */
UCLASS()
class ASHENOATH_API AAshenAshCasketRemnantActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenAshCasketRemnantActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Remnant")
	bool bIsHarvested = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Remnant")
	int32 HarvestFrozenBasalt(AActor* InstigatingPlayer);
};
