// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNovaPostProcessAdapter.generated.h"

/**
 * UAshenNovaPostProcessAdapter
 * Manages post-process memory bleed: slate-grey silhouette shading, heavy chromatic desaturation, and white-flame apex bloom.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNovaPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNovaPostProcessAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void ApplyNovaPostProcess(float ExecutionProgress, float Isolation, float Resolve);
};
