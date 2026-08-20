// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCrucibleSLMCompilerBridgeComponent.generated.h"

/**
 * UAshenCrucibleSLMCompilerBridgeComponent
 * Connects Heartstone Crucible rest sequence to SLM Compiler Subsystem.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCrucibleSLMCompilerBridgeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCrucibleSLMCompilerBridgeComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Crucible")
	void TriggerCrucibleCompilation();
};
