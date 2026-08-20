// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenLorekeeperBeaconGASAbility.generated.h"

/**
 * UAshenLorekeeperBeaconGASAbility
 * GAS ability channeling 20.0 Sanity to reveal hidden lorekeeper runes, secret codex caches, and psychic trails in a 1500uu radius.
 */
UCLASS()
class ASHENOATH_API UAshenLorekeeperBeaconGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenLorekeeperBeaconGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float SanityCost = 20.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float IlluminationRadius = 1500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool CastLorekeeperBeacon(AActor* InstigatorActor);
};
