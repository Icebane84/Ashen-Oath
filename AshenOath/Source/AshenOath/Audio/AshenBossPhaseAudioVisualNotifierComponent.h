// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossPhaseAudioVisualNotifierComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossPhaseAVTriggeredSignature, int32, NewPhase, float, FlashIntensity);

/**
 * UAshenBossPhaseAudioVisualNotifierComponent
 *
 * Drives boss phase change audio-visual sequences (screen flash, camera shake, music stem shift).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossPhaseAudioVisualNotifierComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossPhaseAudioVisualNotifierComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|BossAV")
	void NotifyPhaseTransition(int32 NewPhase, float Intensity = 1.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BossAV|Events")
	FOnBossPhaseAVTriggeredSignature OnPhaseAVTriggered;
};
