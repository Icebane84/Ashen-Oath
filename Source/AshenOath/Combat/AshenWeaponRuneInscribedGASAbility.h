// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenWeaponRuneInscribedGASAbility.generated.h"

/**
 * UAshenWeaponRuneInscribedGASAbility
 * Awakens inscribed weapon runes for high-damage resonant burst attacks.
 */
UCLASS()
class ASHENOATH_API UAshenWeaponRuneInscribedGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenWeaponRuneInscribedGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Rune Ability")
	float RuneResonanceDamage = 140.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Rune Ability")
	bool ActivateRuneBurst(int32 RuneTier);
};
