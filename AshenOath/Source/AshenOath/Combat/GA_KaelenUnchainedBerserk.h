// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_KaelenUnchainedBerserk.generated.h"

/**
 * UGA_KaelenUnchainedBerserk
 *
 * Gameplay Ability for Kaelen's "Unchained" berserker frenzy state.
 * Triggered when Shadow Mark Corruption >= 0.70, shattering psychological
 * restraints via the Glass Shield Protocol.
 *
 * Effects:
 *   - Surges Stamina to max (frenzy energy release)
 *   - Inflicts collateral Sanity damage (15.0f) on nearby allies via psychic bleed (500uu sphere overlap)
 *   - Duration: 8 seconds (then auto-ends)
 *
 * Gate: bCorruptionGateOpen must be set to true by the owning actor's corruption tracking.
 */
UCLASS()
class ASHENOATH_API UGA_KaelenUnchainedBerserk : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_KaelenUnchainedBerserk();

	virtual void ActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayAbilityActivationInfo ActivationInfo,
		const FGameplayEventData* TriggerEventData) override;

	virtual bool CanActivateAbility(
		const FGameplayAbilitySpecHandle Handle,
		const FGameplayAbilityActorInfo* ActorInfo,
		const FGameplayTagContainer* SourceTags = nullptr,
		const FGameplayTagContainer* TargetTags = nullptr,
		OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const override;

	/** Must be set true by owning actor when KaelenCorruption >= 0.70. */
	UPROPERTY(BlueprintReadWrite, Category = "AshenOath|Ability")
	bool bCorruptionGateOpen = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float CorruptionThreshold = 0.70f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float BerserkDuration = 8.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float CorruptionSpike = 0.15f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float CollateralSanityDamage = 15.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float PsychicBleedRadius = 500.0f;

private:
	FTimerHandle BerserkEndTimerHandle;

	void EndBerserkState(FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, FGameplayAbilityActivationInfo ActivationInfo);
};
