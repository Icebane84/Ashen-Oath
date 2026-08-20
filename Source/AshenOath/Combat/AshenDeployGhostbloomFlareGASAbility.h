// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenDeployGhostbloomFlareGASAbility.generated.h"

/**
 * UAshenDeployGhostbloomFlareGASAbility
 * GAS ability allowing Garrett to lob a Ghostbloom Flash Flare to stun lesser units for 4.0s.
 */
UCLASS()
class ASHENOATH_API UAshenDeployGhostbloomFlareGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenDeployGhostbloomFlareGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	float FlareThrowDistanceUnits = 750.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	bool LobFlashFlare(AActor* GarrettActor, FVector TargetLocation);
};
