// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWeaponEnchantmentComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenElementInfusion : uint8
{
	None              UMETA(DisplayName = "None"),
	HolyFire          UMETA(DisplayName = "Holy Fire"),
	AlchemicalFrost   UMETA(DisplayName = "Alchemical Frost"),
	ShadowPoise       UMETA(DisplayName = "Shadow Poise")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeaponEnchantedSignature, FName, ElementTag, float, BonusDamage);

/**
 * UAshenWeaponEnchantmentComponent
 *
 * Component applying alchemical element enchantments to weapons.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponEnchantmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeaponEnchantmentComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeaponEnchantment")
	void ApplyEnchantment(FName ElementTag, float BonusDamage = 15.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeaponEnchantment|Events")
	FOnWeaponEnchantedSignature OnWeaponEnchanted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeaponEnchantment")
	FName ActiveElementTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeaponEnchantment")
	float ActiveBonusDamage = 0.0f;
};
