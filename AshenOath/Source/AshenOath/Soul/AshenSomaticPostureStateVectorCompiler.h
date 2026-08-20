// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticPostureStateVectorCompiler.generated.h"

/**
 * UAshenSomaticPostureStateVectorCompiler
 * Soul component compiling somatic posture alignment parameters into FSoulStateVector authoritative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticPostureStateVectorCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticPostureStateVectorCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float CompiledPostureAlignmentScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileSomaticPostureStateVector(float AlignmentValue);
};
