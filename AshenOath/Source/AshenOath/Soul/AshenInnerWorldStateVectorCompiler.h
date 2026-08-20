// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenInnerWorldStateVectorCompiler.generated.h"

/**
 * UAshenInnerWorldStateVectorCompiler
 * Soul component compiling Inner World memory battle outcomes into FSoulStateVector authoritative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenInnerWorldStateVectorCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenInnerWorldStateVectorCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float CompiledInnerWorldIntegrityScalar = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileInnerWorldStateVector(float MemoryIntegrity);
};
