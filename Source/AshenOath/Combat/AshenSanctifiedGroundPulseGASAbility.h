// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSanctifiedGroundPulseGASAbility.generated.h"

/**
 * UAshenSanctifiedGroundPulseGASAbility
 * GAS ability slamming Oathbringer into the ground, permanently consecrating corrupt ground across an 800.0uu radius.
 */
UCLASS()
class ASHENOATH_API UAshenSanctifiedGroundPulseGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSanctifiedGroundPulseGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float SanctificationRadiusUnits = 800.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	bool ConsecrateGroundZone(FVector SlamLocation);
};
