// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenWeaveTraumaBridgeGASAbility.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTraumaBridgeManifestedSignature, float, SpanUnits, float, SanityHealed, float, FatigueCost);

/**
 * UAshenWeaveTraumaBridgeGASAbility
 * GAS ability projecting a physical, traversable light bridge across abyssal chasms by weaving unintegrated memory echoes
 * (Max span 1200.0uu, heals +15.0 Sanity, adds +0.15 Serafina fatigue).
 */
UCLASS()
class ASHENOATH_API UAshenWeaveTraumaBridgeGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()

public:
	UAshenWeaveTraumaBridgeGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float MaxBridgeSpanUnits = 1200.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float SanityHealAmount = 15.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Weaving")
	float SerafinaFatigueCost = 0.15f;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Weaving|Events")
	FOnTraumaBridgeManifestedSignature OnTraumaBridgeManifested;

	/** Manifests a traversable trauma light bridge between two spatial anchors */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Weaving")
	bool ManifestTraumaBridge(AActor* InstigatorActor, FVector StartLocation, FVector EndLocation);
};
