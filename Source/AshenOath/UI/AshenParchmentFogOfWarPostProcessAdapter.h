// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenParchmentFogOfWarPostProcessAdapter.generated.h"

/**
 * UAshenParchmentFogOfWarPostProcessAdapter
 * Modulates parchment texture vignette overlay and ink wash dissolution across unmapped sectors.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParchmentFogOfWarPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenParchmentFogOfWarPostProcessAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | PostProcess")
	float InkWashOpacity = 1.0f; // 1.0 = fully masked, 0.0 = fully revealed

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | PostProcess")
	void SetInkWashDensity(float InDensity);
};
