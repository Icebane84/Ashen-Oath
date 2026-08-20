// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDualityPostProcessVolumeAdapter.generated.h"

/**
 * UAshenDualityPostProcessVolumeAdapter
 * Adapter modulating post-process volumes during realm shifts.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualityPostProcessVolumeAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDualityPostProcessVolumeAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Visuals")
	void AdjustPostProcessForRealmShift(float RealmShiftBlend);
};
