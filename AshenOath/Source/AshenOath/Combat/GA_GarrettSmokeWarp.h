// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_GarrettSmokeWarp.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSmokeWarpExecutedSignature, AActor*, Target, FVector, WarpDestination, float, Damage);

/**
 * UGA_GarrettSmokeWarp
 *
 * Garrett's smoke teleport and backstab warp strike GAS ability.
 * Teleports Garrett behind an enemy within 600uu smoke coverage and deals 220 Critical Damage.
 */
UCLASS()
class ASHENOATH_API UGA_GarrettSmokeWarp : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UGA_GarrettSmokeWarp();

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float WarpDamage = 220.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Ability")
	float WarpRange = 600.0f;

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Ability|Events")
	FOnSmokeWarpExecutedSignature OnWarpExecuted;
};
