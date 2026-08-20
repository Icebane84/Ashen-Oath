// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenPOSTypes.h"
#include "AshenQualitativeInterpretationEngine.generated.h"

/**
 * UAshenQualitativeInterpretationEngine
 * Engine component translating raw float variables in FSoulStateVector (IntegrationDebt, Resolve, Isolation, Trust) into qualitative narrative states.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenQualitativeInterpretationEngine : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenQualitativeInterpretationEngine();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | POS")
	FAshenQualitativeMindState InterpretSoulStateVector(float IntegrationDebt, float Resolve, float Isolation, float GarrettTrust);
};
