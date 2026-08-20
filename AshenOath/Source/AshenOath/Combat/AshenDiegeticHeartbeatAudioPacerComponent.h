// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenDiegeticHeartbeatAudioPacerComponent.generated.h"

/**
 * UAshenDiegeticHeartbeatAudioPacerComponent
 * Modulates diegetic low-frequency heartbeat audio pulse rate during low health based on Resolve.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticHeartbeatAudioPacerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticHeartbeatAudioPacerComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	float GetHeartbeatPitchMultiplier() const { return HeartbeatPitchMultiplier; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Audio")
	float HeartbeatPitchMultiplier = 1.0f;
};
