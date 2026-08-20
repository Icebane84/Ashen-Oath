// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSulfurousSmokeBalmCloudActor.generated.h"

/**
 * AAshenSulfurousSmokeBalmCloudActor
 * 3D volumetric smoke cloud spawned by Garrett to blind and restrict Kaelen's target acquisition radius to 200uu.
 */
UCLASS()
class ASHENOATH_API AAshenSulfurousSmokeBalmCloudActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSulfurousSmokeBalmCloudActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Containment")
	float SmokeRadiusUnits = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Containment")
	void SpawnDenseSmokeCloud(FVector SpawnLocation);
};
