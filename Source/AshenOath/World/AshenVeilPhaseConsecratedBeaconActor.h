// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenVeilPhaseConsecratedBeaconActor.generated.h"

/**
 * AAshenVeilPhaseConsecratedBeaconActor
 * Interactive world beacon actor stabilizing local veil phase filter environments and purifying corrupted miasma.
 */
UCLASS()
class ASHENOATH_API AAshenVeilPhaseConsecratedBeaconActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenVeilPhaseConsecratedBeaconActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Beacon")
	float StabilizationRadius = 850.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Beacon")
	bool bBeaconActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Beacon")
	bool ActivateVeilPhaseBeacon();
};
