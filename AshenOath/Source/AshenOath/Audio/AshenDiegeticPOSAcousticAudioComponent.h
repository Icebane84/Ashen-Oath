// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticPOSAcousticAudioComponent.generated.h"

/**
 * UAshenDiegeticPOSAcousticAudioComponent
 * Audio component modulating diegetic page turn rustles, campfire crackles, and sanctuary chime SFX for Psychological OS screens.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticPOSAcousticAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticPOSAcousticAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float PageRustleVolume = 0.80f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerPageRustleAudio();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerSanctuaryChimeAudio();
};
