// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEnemyFamilyVeilHoundComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVeilHoundStealthStateChangedSignature, bool, bIsStealthed, float, PounceDamageMultiplier);

/**
 * UAshenEnemyFamilyVeilHoundComponent
 *
 * Veil Hound stealth ambush AI component projecting into 3 distinct layers under Constitutional Law #476:
 * Layer 1 (Combat): Pounce execution damage multiplier from stealth.
 * Layer 2 (VFX/Audio): Invisibility cloak distortion & low growl MetaSound.
 * Layer 3 (Dialogue): Companion alert bark when growl is heard.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEnemyFamilyVeilHoundComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenEnemyFamilyVeilHoundComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EnemyFamily")
	void SetHoundStealthState(bool bStealthed);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EnemyFamily|Events")
	FOnVeilHoundStealthStateChangedSignature OnStealthStateChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EnemyFamily")
	bool bIsStealthed = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EnemyFamily")
	float PounceDamageMultiplier = 1.5f;
};
