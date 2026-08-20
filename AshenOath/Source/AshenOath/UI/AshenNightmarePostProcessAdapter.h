// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNightmarePostProcessAdapter.generated.h"

/**
 * UAshenNightmarePostProcessAdapter
 * Manages post-process reality sundering: red-shifted chromatic aberration, screen tearing, and desaturation pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNightmarePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNightmarePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyNightmareVisualDistortion(float IncursionIntensity, float StrainLevel);
};
