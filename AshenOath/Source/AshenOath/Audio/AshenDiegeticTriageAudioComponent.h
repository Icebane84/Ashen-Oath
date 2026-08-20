// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticTriageAudioComponent.generated.h"

/**
 * UAshenDiegeticTriageAudioComponent
 * Plays diegetic dialogue sounds: muffled wet coughs, strained linen unwrapping, and heart-rate tempo shifts during relational triage.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticTriageAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticTriageAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayMuffledCoughSFX();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayBandageUnwrapSFX();
};
