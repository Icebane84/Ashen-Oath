// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenVeilConsecratedBeaconActor.generated.h"

/**
 * AAshenVeilConsecratedBeaconActor
 * Interactive sanctuary world beacon actor stabilizing local veil phase environment and purifying miasma.
 */
UCLASS()
class ASHENOATH_API AAshenVeilConsecratedBeaconActor : public AActor
{
	GENERATED_BODY()

public:
	AAshenVeilConsecratedBeaconActor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	float StabilizationRadius = 750.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Sanctuary")
	bool bBeaconActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Sanctuary")
	bool ActivateConsecratedBeacon();
};
