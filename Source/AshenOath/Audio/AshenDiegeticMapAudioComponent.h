// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticMapAudioComponent.generated.h"

/**
 * UAshenDiegeticMapAudioComponent
 * Audio component modulating diegetic parchment map unfolds, graphite pin scratches, and zoom transition SFX.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticMapAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticMapAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float MapUnfoldVolume = 0.70f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerMapUnfoldAudio();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerGraphiteScratchAudio();
};
