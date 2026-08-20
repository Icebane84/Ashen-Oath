// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenCorruptedMiasmaHazardVolume.generated.h"

/**
 * AAshenCorruptedMiasmaHazardVolume
 * Environmental volume applying somatic miasma damage, post-process chromatic aberration, and audio distortion.
 */
UCLASS()
class ASHENOATH_API AAshenCorruptedMiasmaHazardVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenCorruptedMiasmaHazardVolume();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hazard")
	float MiasmaCorruptionDPS = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Hazard")
	float MiasmaChromaticAberrationIntensity = 0.85f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Hazard")
	void ApplyMiasmaCorruptionToActor(AActor* TargetActor, float DeltaTime);
};
