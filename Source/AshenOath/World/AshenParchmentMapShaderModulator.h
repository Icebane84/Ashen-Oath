// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenParchmentMapShaderModulator.generated.h"

/**
 * UAshenParchmentMapShaderModulator
 * Material Parameter Collection (MPC) modulator driving PBR parchment soot, ink bleed, and vignetting overlays for map Slate rendering.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParchmentMapShaderModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParchmentMapShaderModulator();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Map Material")
	float ParchmentSootScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Map Material")
	void UpdateMapParchmentShaderParameters(float Soot, float InkBleed);
};
