// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticBeaconHarmonicChimeAudioComponent.generated.h"

/**
 * UAshenDiegeticBeaconHarmonicChimeAudioComponent
 * Audio component modulating beacon harmonic chime audio SFX during veil phase stabilization.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticBeaconHarmonicChimeAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticBeaconHarmonicChimeAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float BeaconHarmonicVolume = 0.6f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerBeaconHarmonicChimePulse();
};
