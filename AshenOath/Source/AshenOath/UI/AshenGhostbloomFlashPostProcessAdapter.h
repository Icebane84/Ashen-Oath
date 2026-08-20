// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGhostbloomFlashPostProcessAdapter.generated.h"

/**
 * UAshenGhostbloomFlashPostProcessAdapter
 * Modulates high-intensity white screen bloom flash and retinal afterimage persistence upon Ghostbloom flare detonations.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGhostbloomFlashPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGhostbloomFlashPostProcessAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | PostProcess")
	float FlashBloomIntensity = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | PostProcess")
	void TriggerFlashBloom(float Intensity);
};
