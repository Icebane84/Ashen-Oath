// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenMindscapeOathReactivityMPCModulator.generated.h"

/**
 * UAshenMindscapeOathReactivityMPCModulator
 * Modulator updating MPC_OathCorruption to drive wall darkness and floor crack density across Mindscape materials.
 */
UCLASS()
class ASHENOATH_API UAshenMindscapeOathReactivityMPCModulator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Shaders")
	float OathCorruptionScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shaders")
	void UpdateMPCForOathBurden(float OathBurden);
};
