// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenArmorSootSeamGrimeDriver.generated.h"

/**
 * UAshenArmorSootSeamGrimeDriver
 * Component driving armor metalness loss, roughness accumulation, and seam grime darkening parameters across character armor sets.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenArmorSootSeamGrimeDriver : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenArmorSootSeamGrimeDriver();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Shader Driver")
	float CurrentRoughnessScalar = 0.20f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shader Driver")
	void ApplyArmorSootParameters(float SootMask, float SeamGrimeMask);
};
