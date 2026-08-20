// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenResonantBeaconEchoGASAbility.generated.h"

/**
 * UAshenResonantBeaconEchoGASAbility
 * GAS ability releasing a psychic pulse from the Living Journal, aligning the astrolabe compass needle to the nearest active Heartstone Sanctuary.
 */
UCLASS()
class ASHENOATH_API UAshenResonantBeaconEchoGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenResonantBeaconEchoGASAbility();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	bool TriggerBeaconPulse(FVector PlayerLocation, FVector SanctuaryLocation);
};
