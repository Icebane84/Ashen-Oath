// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenShadowMarkCorruptionMPCModulator.generated.h"

/**
 * UAshenShadowMarkCorruptionMPCModulator
 * Real-time dynamic driving of MPC_ShadowMarkC emissive veins across Kaelen's mesh.
 */
UCLASS()
class ASHENOATH_API UAshenShadowMarkCorruptionMPCModulator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Shaders")
	float ShadowMarkEmissiveIntensity = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shaders")
	void UpdateShadowMarkEmissiveScalar(float CorruptionRatio);
};
