// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMassKineticTypes.h"
#include "AshenCameraResistanceDilationComponent.generated.h"

/**
 * UAshenCameraResistanceDilationComponent
 * 
 * Compresses FOV during blade drag (90 to 76 deg) and elastically snaps outward
 * (96 to 90 deg) when cutting through matter.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCameraResistanceDilationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCameraResistanceDilationComponent();

	/** Calculates target camera FOV during blade matter resistance */
	UFUNCTION(BlueprintPure, Category = "Ashen|Combat|Kinetic")
	float CalculateCompressedFOV(float SubmergedVolumeCM3) const;
};
