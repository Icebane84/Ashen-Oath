// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticCrisisAcousticAudioComponent.generated.h"

/**
 * UAshenDiegeticCrisisAcousticAudioComponent
 * Audio component modulating acoustic muffling, wet heartbeat pulses, and silver bell tones during crisis timeline stages.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticCrisisAcousticAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticCrisisAcousticAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float AcousticMuffleCutoffFrequency = 400.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerAcousticMuffle();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerSilverBellResolutionTone();
};
