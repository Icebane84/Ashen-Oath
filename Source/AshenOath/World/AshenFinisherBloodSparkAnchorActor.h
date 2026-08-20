// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenFinisherBloodSparkAnchorActor.generated.h"

/**
 * AAshenFinisherBloodSparkAnchorActor
 * World actor rendering directional blood spark VFX anchors.
 */
UCLASS()
class ASHENOATH_API AAshenFinisherBloodSparkAnchorActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenFinisherBloodSparkAnchorActor();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void SpawnDirectionalBloodSparks(FVector ImpactNormal);
};
