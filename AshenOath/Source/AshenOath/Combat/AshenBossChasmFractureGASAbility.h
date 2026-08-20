// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenBossChasmFractureGASAbility.generated.h"

/**
 * UAshenBossChasmFractureGASAbility
 * Boss GAS ability splitting the arena floor with a bottomless void fissure (1000.0uu span), forcing Serafina to weave a Trauma Light Bridge.
 */
UCLASS()
class ASHENOATH_API UAshenBossChasmFractureGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenBossChasmFractureGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Boss")
	float FissureLengthUnits = 1000.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	bool FractureArenaFloor(FVector OriginLocation, FVector Direction);
};
