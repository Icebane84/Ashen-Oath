// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticTrialOfWillAudioComponent.generated.h"

/**
 * UAshenDiegeticTrialOfWillAudioComponent
 * Manages audio muffling, low-pass filter sweeps, and dramatic low-frequency heartbeat thuds during the 0.75s time dilation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticTrialOfWillAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticTrialOfWillAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerTimeDilationAudioFilter(bool bActive);
};
