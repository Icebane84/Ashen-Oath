// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSomaticIdentityStateVectorCompiler.generated.h"

/**
 * UAshenSomaticIdentityStateVectorCompiler
 * Soul component compiling somatic identity echo values directly into FSoulStateVector authoritative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSomaticIdentityStateVectorCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSomaticIdentityStateVectorCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float CompiledIdentityEchoScalar = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileSomaticIdentityStateVector(float EchoValue);
};
