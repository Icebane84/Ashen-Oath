// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticDualityAudioSpatializer.generated.h"

/**
 * UAshenDiegeticDualityAudioSpatializer
 * 3D spatialized MetaSounds shifting ambient soundscapes between physical world and sundered realm.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticDualityAudioSpatializer : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticDualityAudioSpatializer();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void SpatializeDualityAudio(float RealmShiftBlend);
};
