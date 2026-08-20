// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenShadowSeepagePostProcessAdapter.generated.h"

/**
 * UAshenShadowSeepagePostProcessAdapter
 * Manages post-process peripheral dark vignetting and radial chromatic aberration scaling dynamically with Kaelen's corruption seepage phase.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShadowSeepagePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenShadowSeepagePostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplySeepagePostProcess(EShadowSeepagePhase Phase, float Corruption);
};
