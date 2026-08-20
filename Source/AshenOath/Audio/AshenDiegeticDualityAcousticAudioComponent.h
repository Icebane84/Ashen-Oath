// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticDualityAcousticAudioComponent.generated.h"

/**
 * UAshenDiegeticDualityAcousticAudioComponent
 * Audio component modulating transformation hums, blade rune ignition audio, and cloth tearing SFX.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticDualityAcousticAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticDualityAcousticAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float TransformationHumVolume = 0.85f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerTransformationHumAudio();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerRuneIgnitionAudio();
};
