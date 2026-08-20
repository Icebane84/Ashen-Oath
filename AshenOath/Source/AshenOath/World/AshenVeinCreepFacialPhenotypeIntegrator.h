// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenVeinCreepFacialPhenotypeIntegrator.generated.h"

/**
 * UAshenVeinCreepFacialPhenotypeIntegrator
 * Connects vein creep shader and facial expression components to FSoulStateVector.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVeinCreepFacialPhenotypeIntegrator : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenVeinCreepFacialPhenotypeIntegrator();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Somatic")
	float GetVeinCreepScalar() const { return VeinCreepScalar; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|Somatic")
	float VeinCreepScalar = 0.0f;
};
