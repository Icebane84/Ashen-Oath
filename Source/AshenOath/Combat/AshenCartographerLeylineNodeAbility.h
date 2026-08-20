// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenCartographerLeylineNodeAbility.generated.h"

/**
 * UAshenCartographerLeylineNodeAbility
 * Gameplay Ability utilizing Heartstone leyline map coordinates to manifest a fast-travel sanctuary pulse.
 */
UCLASS()
class ASHENOATH_API UAshenCartographerLeylineNodeAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenCartographerLeylineNodeAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	float LeylinePulseRadius = 1200.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool ManifestLeylineSanctuaryPulse();
};
