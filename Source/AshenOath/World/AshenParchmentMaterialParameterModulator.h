// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenParchmentMaterialParameterModulator.generated.h"

/**
 * UAshenParchmentMaterialParameterModulator
 * Component modulating Material Parameter Collection (MPC) scalars driving Slate parchment shader ash overlays and vein creep.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenParchmentMaterialParameterModulator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenParchmentMaterialParameterModulator();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Material Modulator")
	float AshStainCoverageScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Material Modulator")
	void ModulateParchmentMaterialParameters(float AshCoverage, float VeinCreep);
};
