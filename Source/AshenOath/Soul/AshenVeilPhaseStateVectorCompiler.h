// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenVeilPhaseStateVectorCompiler.generated.h"

/**
 * UAshenVeilPhaseStateVectorCompiler
 * Soul component compiling veil phase shift parameters directly into FSoulStateVector authorative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVeilPhaseStateVectorCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenVeilPhaseStateVectorCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float CompiledPhaseDissonanceScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileVeilPhaseStateVector(float ShiftIntensity);
};
