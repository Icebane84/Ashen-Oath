// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenUnchainedVisionPostProcessAdapter.generated.h"

/**
 * UAshenUnchainedVisionPostProcessAdapter
 * Modulates high-contrast monochromatic tunnel-vision post-processing and pulsing crimson edge vignettes during Kaelen's unchained state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnchainedVisionPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenUnchainedVisionPostProcessAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Visuals")
	float TunnelVisionIntensity = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyUnchainedVisionFX(float CorruptionAmount);
};
