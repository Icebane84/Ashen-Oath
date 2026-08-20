// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenConstellationWaypointActor.generated.h"

/**
 * AAshenConstellationWaypointActor
 * Regional cartographic waypoint anchoring memory leylines between Kaelen, Serafina, and Garrett.
 */
UCLASS()
class ASHENOATH_API AAshenConstellationWaypointActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenConstellationWaypointActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Map")
	bool bIsWaypointHarmonized = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map")
	bool HarmonizeWaypoint(AActor* InstigatingPlayer);
};
