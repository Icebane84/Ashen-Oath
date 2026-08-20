// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Soul/AshenSoulConstellationTypes.h"
#include "AshenDebtEscalationMPCShaderModulator.generated.h"

/**
 * UAshenDebtEscalationMPCShaderModulator
 * Modulator updating Material Parameter Collections (MPC_IntegrationDebt, MPC_DebtStage, MPC_NoiseIntensity) across world shaders.
 */
UCLASS()
class ASHENOATH_API UAshenDebtEscalationMPCShaderModulator : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Shaders")
	float ActiveNoiseIntensityScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shaders")
	void ModulateMPCShaderParameters(float DebtValue, EAshenIntegrationDebtStage Stage);
};
