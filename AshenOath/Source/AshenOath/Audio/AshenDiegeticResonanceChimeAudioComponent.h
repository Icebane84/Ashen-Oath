// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticResonanceChimeAudioComponent.generated.h"

/**
 * UAshenDiegeticResonanceChimeAudioComponent
 * Audio component modulating diegetic resonance harmonic chime audio SFX during posture alignment.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticResonanceChimeAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticResonanceChimeAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float ResonanceChimeVolume = 0.65f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerResonanceHarmonicChimePulse();
};
