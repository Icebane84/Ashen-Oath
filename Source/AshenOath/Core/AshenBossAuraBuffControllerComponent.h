// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossAuraBuffControllerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnBossAuraPulseSignature, float, AuraDamage, float, Radius);

/**
 * UAshenBossAuraBuffControllerComponent
 *
 * Emits elemental damage pulses (Void, Fire, Frost) to nearby player characters within 400u.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossAuraBuffControllerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBossAuraBuffControllerComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|BossAura")
	void PulseAuraDamage();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|BossAura")
	float AuraDamagePerPulse = 25.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|BossAura")
	float AuraRadius = 400.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|BossAura|Events")
	FOnBossAuraPulseSignature OnAuraPulse;
};
