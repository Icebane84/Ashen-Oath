// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenChillingSilenceVacuumAudioVolume.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVacuumAudioTriggeredSignature, float, AmbientVacuumVolume, float, HeartbeatPulsePitch);

/**
 * AAshenChillingSilenceVacuumAudioVolume
 *
 * World Volume executing complete acoustic vacuum & wet heartbeat pulse during crisis dilation (PRS-001 Combat Blueprint V5.0).
 */
UCLASS()
class ASHENOATH_API AAshenChillingSilenceVacuumAudioVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenChillingSilenceVacuumAudioVolume();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VacuumAudio")
	void TriggerChillingSilenceVacuum(bool bEnableVacuum);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VacuumAudio|Events")
	FOnVacuumAudioTriggeredSignature OnVacuumAudioTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|VacuumAudio")
	bool bIsVacuumActive = false;
};
