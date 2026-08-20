// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWhiteFlameShockwaveEmitterComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWhiteFlameShockwaveEmittedSignature, FVector, EmitterLocation, float, RadialImpulsePower);

/**
 * UAshenWhiteFlameShockwaveEmitterComponent
 *
 * Component emitting radial White Flame shockwaves upon perfect deflections (Smite Riposte, PRS-001 Combat Blueprint).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWhiteFlameShockwaveEmitterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWhiteFlameShockwaveEmitterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WhiteFlameEmitter")
	void EmitWhiteFlameShockwave(FVector Location, float Power = 800.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WhiteFlameEmitter|Events")
	FOnWhiteFlameShockwaveEmittedSignature OnShockwaveEmitted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WhiteFlameEmitter")
	int32 TotalShockwavesEmitted = 0;
};
