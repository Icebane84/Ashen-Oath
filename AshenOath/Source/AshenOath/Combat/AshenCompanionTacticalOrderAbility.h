// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AshenCompanionTacticalOrderAbility.generated.h"

UENUM(BlueprintType)
enum class EAshenSquadCommand : uint8
{
	Garrett_PauldronVault UMETA(DisplayName = "Garrett: Pauldron Vault Flank (100% Poise Stagger)"),
	Garrett_CaltropSnare  UMETA(DisplayName = "Garrett: Caltrop Frost Snare (Ranged Slowdown)"),
	Serafina_ConduitBurst UMETA(DisplayName = "Serafina: Conduit Flame Lance (Thermal Slag 1.0)"),
	Serafina_AegisBarrier UMETA(DisplayName = "Serafina: Consecrated Aegis Barrier (Defensive Ward)")
};

/**
 * UAshenCompanionTacticalOrderAbility
 *
 * Base Gameplay Ability executing targeted companion squad commands
 * with motion warping and asymmetric fatigue accrual.
 */
UCLASS()
class ASHENOATH_API UAshenCompanionTacticalOrderAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCompanionTacticalOrderAbility();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Tactical")
	EAshenSquadCommand GetSquadCommandType() const { return SquadCommandType; }

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Tactical")
	void SetTargetActor(AActor* InTarget) { TargetActor = InTarget; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath|Tactical")
	EAshenSquadCommand SquadCommandType = EAshenSquadCommand::Garrett_PauldronVault;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath|Tactical", meta = (ClampMin = "0.0", ClampMax = "1.0"))
	float FatigueAccrual = 0.25f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath|Tactical")
	TWeakObjectPtr<AActor> TargetActor;
};
