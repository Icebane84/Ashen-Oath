// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticFinisherGASAudioComponent.generated.h"

/**
 * UAshenDiegeticFinisherGASAudioComponent
 * Manages audio cues for character finisher GAS abilities: line-hook grapple whoosh, staff channel squeal, and sub-bass nova detonation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticFinisherGASAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticFinisherGASAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayGrappleWhooshCue();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayNovaDetonationCue();
};
