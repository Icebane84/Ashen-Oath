// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticEchoHarmonizerAudioComponent.generated.h"

/**
 * UAshenDiegeticEchoHarmonizerAudioComponent
 * Audio component modulating diegetic echo harmonizer frequency parameters based on veil phase shift values.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticEchoHarmonizerAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticEchoHarmonizerAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float EchoHarmonizerVolume = 0.7f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateEchoHarmonizerFrequency(float PhaseShiftIntensity);
};
