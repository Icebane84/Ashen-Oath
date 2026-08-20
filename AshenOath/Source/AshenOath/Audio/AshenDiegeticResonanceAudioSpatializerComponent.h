// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticResonanceAudioSpatializerComponent.generated.h"

/**
 * UAshenDiegeticResonanceAudioSpatializerComponent
 * Audio component spatializing diegetic resonance frequencies based on character 3D spatial velocity and posture alignment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticResonanceAudioSpatializerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticResonanceAudioSpatializerComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float SpatializedResonanceVolume = 0.75f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateSpatializedResonanceFrequencies(float PostureScalar);
};
