// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCrimsonStaticPostProcessAdapter.generated.h"

/**
 * UAshenCrimsonStaticPostProcessAdapter
 * Modulates screen-space border crimson static noise bleed when breathing cadence or trigger locks fail.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCrimsonStaticPostProcessAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCrimsonStaticPostProcessAdapter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | PostProcess")
	float CrimsonStaticIntensity = 0.0f; // 0.0 to 1.0

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | PostProcess")
	void TriggerCrimsonStaticFlash(float Intensity);
};
