// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenVeilPhaseFilterStateVectorCompiler.generated.h"

/**
 * UAshenVeilPhaseFilterStateVectorCompiler
 * Soul component compiling veil phase filter parameters into FSoulStateVector authoritative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenVeilPhaseFilterStateVectorCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenVeilPhaseFilterStateVectorCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float CompiledVeilPhaseFilterScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileVeilPhaseFilterStateVector(float FilterValue);
};
