// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCrisisStateVectorCompiler.generated.h"

/**
 * UAshenCrisisStateVectorCompiler
 * Soul component compiling crisis state resolution values into FSoulStateVector authoritative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCrisisStateVectorCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCrisisStateVectorCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float CompiledCrisisStateScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileCrisisStateVector(float CrisisValue);
};
