// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSpectralLanternPostProcessAdapter.generated.h"

/**
 * UAshenSpectralLanternPostProcessAdapter
 * Violet-phosphor spectral lighting overlay illuminating hidden markings and revealing spirit trails.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSpectralLanternPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenSpectralLanternPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplySpectralLanternPostProcess(bool bIsLit, float Intensity);
};
