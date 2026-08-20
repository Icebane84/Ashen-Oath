// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDualityStateVectorCompiler.generated.h"

/**
 * UAshenDualityStateVectorCompiler
 * Soul component compiling Duality Engine transformation values into FSoulStateVector authoritative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDualityStateVectorCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDualityStateVectorCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float CompiledDualityStateScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileDualityStateVector(float DualityValue);
};
