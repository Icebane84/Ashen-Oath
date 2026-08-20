// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenVeilPhaseDissonanceVolume.generated.h"

/**
 * AAshenVeilPhaseDissonanceVolume
 * Spatial volume component applying dimensional veil phase shifts and mesh distortion parameters to actors inside.
 */
UCLASS()
class ASHENOATH_API AAshenVeilPhaseDissonanceVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenVeilPhaseDissonanceVolume();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float VeilDissonanceIntensity = 0.75f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void ApplyVeilPhaseDistortionToActor(AActor* TargetActor);
};
