// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWhiteFlamePostProcessAdapter.generated.h"

/**
 * UAshenWhiteFlamePostProcessAdapter
 * Modulates high-key radiant exposure, golden bloom halos, and complete erasure of dark shadow vignettes during the White Flame state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlamePostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenWhiteFlamePostProcessAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | PostProcess")
	float RadiantBloomIntensity = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | PostProcess")
	void ApplyWhiteFlamePostProcess(bool bWhiteFlameActive);
};
