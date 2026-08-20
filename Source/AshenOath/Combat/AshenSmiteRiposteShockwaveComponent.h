// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSmiteRiposteShockwaveComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSmiteRiposteShockwaveTriggeredSignature, float, ShockwaveRadius, float, WhiteFlameDamage);

/**
 * UAshenSmiteRiposteShockwaveComponent
 *
 * Component triggering zero-cost radial shockwave of White Flame on deflections (Smite Riposte, PRS-001 Combat Blueprint).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSmiteRiposteShockwaveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSmiteRiposteShockwaveComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SmiteRiposte")
	void TriggerSmiteRiposte(float Radius = 600.0f, float Damage = 250.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SmiteRiposte|Events")
	FOnSmiteRiposteShockwaveTriggeredSignature OnSmiteRiposteTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SmiteRiposte")
	int32 TotalSmiteRipostesExecuted = 0;
};
