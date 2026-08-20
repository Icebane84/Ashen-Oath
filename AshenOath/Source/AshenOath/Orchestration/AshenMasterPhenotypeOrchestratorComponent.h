// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenMasterPhenotypeOrchestratorComponent.generated.h"

/**
 * UAshenMasterPhenotypeOrchestratorComponent
 * Attaches to AAshenOathCharacter, coordinating state invalidation dispatches across all phenotype integrators.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMasterPhenotypeOrchestratorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMasterPhenotypeOrchestratorComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Orchestration")
	void DispatchPhenotypeUpdates(const FSoulStateVector& NewState);
};
