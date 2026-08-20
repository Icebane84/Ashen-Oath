// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticSovereignHarmonicChimeAudioComponent.generated.h"

/**
 * UAshenDiegeticSovereignHarmonicChimeAudioComponent
 * Audio component modulating diegetic sovereign harmonic chime audio SFX during ascension pulses.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticSovereignHarmonicChimeAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticSovereignHarmonicChimeAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float SovereignHarmonicVolume = 0.85f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerSovereignHarmonicChimePulse();
};
