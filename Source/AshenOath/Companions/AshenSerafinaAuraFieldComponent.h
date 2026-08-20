// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSerafinaAuraFieldComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAuraFieldHealTickSignature, float, HealAmount);

/**
 * UAshenSerafinaAuraFieldComponent
 *
 * Serafina's persistent holy aura field. When active, pulses every 3 seconds
 * healing all allied pawns within 450 units for 12 HP per tick.
 * Uses SphereOverlapActors for spatial detection. Maximum 8 concurrent allies healed.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSerafinaAuraFieldComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSerafinaAuraFieldComponent();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Aura")
	void ActivateAura();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Aura")
	void DeactivateAura();

	UFUNCTION(BlueprintPure, Category = "AshenOath|Aura")
	bool IsAuraActive() const { return bAuraActive; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Aura")
	float AuraRadius = 450.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Aura")
	float HealPerTick = 12.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Aura")
	float PulseInterval = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Aura")
	int32 MaxAlliesHealed = 8;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Aura|Events")
	FOnAuraFieldHealTickSignature OnAuraHealTick;

private:
	bool bAuraActive = false;
	FTimerHandle AuraPulseTimer;

	void PulseAuraHeal();
};
