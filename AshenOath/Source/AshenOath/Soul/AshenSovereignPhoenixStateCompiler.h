// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSovereignPhoenixStateCompiler.generated.h"

/**
 * UAshenSovereignPhoenixStateCompiler
 * Soul component compiling Grand Master Sovereign Phoenix State Vector values directly into FSoulStateVector authoritative truth.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSovereignPhoenixStateCompiler : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSovereignPhoenixStateCompiler();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Soul")
	float SovereignAscensionProgress = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	void CompileSovereignStateVector();
};
