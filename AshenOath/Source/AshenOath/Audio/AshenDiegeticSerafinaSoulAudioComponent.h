// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticSerafinaSoulAudioComponent.generated.h"

/**
 * UAshenDiegeticSerafinaSoulAudioComponent
 * Audio component playing ethereal choir hums, soul tether chimes, and heartbeat quickening under burnout.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticSerafinaSoulAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticSerafinaSoulAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayTransferenceChoirHum();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayBurnoutHeartbeatPulse(float BurnoutLevel);
};
