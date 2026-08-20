// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticPsychologicalResonanceAudioComponent.generated.h"

/**
 * UAshenDiegeticPsychologicalResonanceAudioComponent
 * Audio component emitting diegetic psychological resonance audio harmonics based on identity echo strength.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticPsychologicalResonanceAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticPsychologicalResonanceAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float PsychologicalResonanceVolume = 0.6f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdatePsychologicalResonanceHarmonics(float EchoStrength);
};
