// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticMiasmaWhisperAudioComponent.generated.h"

/**
 * UAshenDiegeticMiasmaWhisperAudioComponent
 * Actor Component modulating spatialized audio whispers based on environmental miasma corruption density.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticMiasmaWhisperAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticMiasmaWhisperAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float WhisperSpatialIntensity = 0.5f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateWhisperPitchModulation(float CorruptionLevel);
};
