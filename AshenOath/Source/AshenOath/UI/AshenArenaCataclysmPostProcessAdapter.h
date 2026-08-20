// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenArenaCataclysmPostProcessAdapter.generated.h"

/**
 * UAshenArenaCataclysmPostProcessAdapter
 * Modulates arena void desaturation, radial chromatic aberration, and screen-space distortion during Phase 3 Apex Cataclysm.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenArenaCataclysmPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenArenaCataclysmPostProcessAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | PostProcess")
	float CataclysmDistortionIntensity = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | PostProcess")
	void SetCataclysmFXState(bool bEnableCataclysmFX);
};
