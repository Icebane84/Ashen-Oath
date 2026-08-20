// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCognitiveAIStateVectorCompiler.generated.h"

/**
 * UAshenCognitiveAIStateVectorCompiler
 * Soul component compiling Cognitive AI utility and threat states into FSoulStateVector authoritative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCognitiveAIStateVectorCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCognitiveAIStateVectorCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float CompiledAIThreatScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileCognitiveStateVector(float ThreatValue);
};
