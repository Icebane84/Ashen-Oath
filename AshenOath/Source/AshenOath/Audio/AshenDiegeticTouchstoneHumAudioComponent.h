// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticTouchstoneHumAudioComponent.generated.h"

/**
 * UAshenDiegeticTouchstoneHumAudioComponent
 * Audio component modulating low-frequency touchstone hum based on player proximity and sanity state.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticTouchstoneHumAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticTouchstoneHumAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float TouchstoneHumVolume = 0.8f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateHumProximityVolume(float DistanceToPlayer);
};
