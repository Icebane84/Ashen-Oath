// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMiasmaDispersalVolumeActor.generated.h"

/**
 * AAshenMiasmaDispersalVolumeActor
 * Thick shadow miasma volume burning away dynamically under lantern light.
 */
UCLASS()
class ASHENOATH_API AAshenMiasmaDispersalVolumeActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMiasmaDispersalVolumeActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Miasma")
	float MiasmaDensity = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Miasma")
	void DisperseMiasma(float LightIntensity);
};
