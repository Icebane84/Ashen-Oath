// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenReclaimedMemoryBeaconActor.generated.h"

/**
 * AAshenReclaimedMemoryBeaconActor
 * Beacon actor crystallizing reclaimed memory fragments in the physical world.
 */
UCLASS()
class ASHENOATH_API AAshenReclaimedMemoryBeaconActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenReclaimedMemoryBeaconActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	FName BoundMemoryID;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void IgniteMemoryBeacon();
};
