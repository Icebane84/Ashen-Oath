// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossPhaseParticleControllerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossPhaseFXTriggeredSignature, int32, NewPhaseIndex, FName, ParticleFXID);

/**
 * UAshenBossPhaseParticleControllerComponent
 *
 * Spawns phase transition energy bursts, elemental ground crack decals, and aura glows on boss actors.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossPhaseParticleControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossPhaseParticleControllerComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|BossVFX")
	void TriggerPhaseFX(int32 NewPhaseIndex, FName ParticleFXID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BossVFX|Events")
	FOnBossPhaseFXTriggeredSignature OnBossPhaseFXTriggered;
};
