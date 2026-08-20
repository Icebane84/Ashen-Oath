// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticTouchstoneChimeAudioComponent.generated.h"

/**
 * UAshenDiegeticTouchstoneChimeAudioComponent
 * Audio component modulating diegetic touchstone hum and harmonic chime audio SFX.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticTouchstoneChimeAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticTouchstoneChimeAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float TouchstoneHumVolume = 0.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerTouchstoneHarmonicPulse();
};
