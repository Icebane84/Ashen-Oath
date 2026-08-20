// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenDualityTypes.h"
#include "AshenCorruptionMaskInterpolator.generated.h"

/**
 * UAshenCorruptionMaskInterpolator
 * Component compiling channel-packed RGBA mask values (T_CorruptionMasks: R=Soot, G=Seam Grime, B=Tabard Raggedness, A=Emissive).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCorruptionMaskInterpolator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCorruptionMaskInterpolator();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Duality Mask")
	FAshenCorruptionMaskValues CalculateCorruptionMaskChannelValues(float CorruptionAmount);
};
