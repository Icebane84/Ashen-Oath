// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenVeilPhaseDissonanceFilterVolume.generated.h"

/**
 * AAshenVeilPhaseDissonanceFilterVolume
 * Spatial volume applying somatic veil phase distortion filters and environmental mesh displacement parameters.
 */
UCLASS()
class ASHENOATH_API AAshenVeilPhaseDissonanceFilterVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenVeilPhaseDissonanceFilterVolume();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float VeilPhaseFilterIntensity = 0.90f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void ApplyVeilPhaseFilterToActor(AActor* TargetActor);
};
