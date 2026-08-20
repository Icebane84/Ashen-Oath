// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerSomaticVFXComponent.generated.h"

/**
 * UAshenOathbringerSomaticVFXComponent — BUILD 2,000 MILESTONE COMPONENT
 * Primary UI-Less Somatic Weapon Visualizer for Oathbringer.
 * Drives Nightsteel corruption stain spread across the blade fuller and garnet wolf-head emissive eye glow.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerSomaticVFXComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenOathbringerSomaticVFXComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float NightsteelStainCoverage = 0.0f; // 0.0 (Clean) to 1.0 (Full Void Corruption)

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Somatic")
	float WolfHeadGarnetGlow = 0.2f; // 0.2 (Amber Flame) to 3.0 (Void Fire)

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Somatic")
	void UpdateOathbringerSomaticState(float CorruptionScalar, bool bIsDarkMode);
};
