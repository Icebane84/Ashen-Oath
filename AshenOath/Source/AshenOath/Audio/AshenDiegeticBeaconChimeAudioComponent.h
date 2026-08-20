// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticBeaconChimeAudioComponent.generated.h"

/**
 * UAshenDiegeticBeaconChimeAudioComponent
 * Audio component modulating consecrated beacon chime harmonics when purifying corrupted miasma.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticBeaconChimeAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticBeaconChimeAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float BeaconChimeHarmonics = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerBeaconHarmonicChime();
};
