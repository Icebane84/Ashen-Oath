// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnemyFamilyAshWalkerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAshWalkerHyperArmorStateChangedSignature, bool, bIsHyperArmorActive, float, DamageMitigationPercent);

/**
 * UAshenEnemyFamilyAshWalkerComponent
 *
 * Ash Walker heavy elite component projecting into 3 distinct layers under Constitutional Law #476:
 * Layer 1 (Combat): Unstoppable hyper armor state & 50% damage mitigation.
 * Layer 2 (VFX/Audio): Ash cloud trail particles & heavy footstep MetaSound.
 * Layer 3 (Dialogue): Companion warning voice bark (e.g., Garrett: "Heavy Ash Walker! Don't trade hits!").
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEnemyFamilyAshWalkerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEnemyFamilyAshWalkerComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EnemyFamily")
	void SetHyperArmorState(bool bActive);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EnemyFamily|Events")
	FOnAshWalkerHyperArmorStateChangedSignature OnHyperArmorStateChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EnemyFamily")
	bool bIsHyperArmorActive = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EnemyFamily")
	float DamageMitigationPercent = 50.0f;
};
