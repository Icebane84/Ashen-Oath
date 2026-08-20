// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenWeaveTraumaBridgeGASAbility.generated.h"

/**
 * UAshenWeaveTraumaBridgeGASAbility
 * GAS ability projecting a physical, traversable light bridge across abyssal chasms by weaving unintegrated memory echoes.
 */
UCLASS()
class ASHENOATH_API UAshenWeaveTraumaBridgeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenWeaveTraumaBridgeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float MaxBridgeSpanUnits = 1200.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	bool ManifestTraumaBridge(FVector StartLocation, FVector EndLocation);
};
