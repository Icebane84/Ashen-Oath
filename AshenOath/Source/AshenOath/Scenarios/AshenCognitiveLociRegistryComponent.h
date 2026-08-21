// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Scenarios/AshenScenario4WhisperwoodTypes.h"
#include "AshenCognitiveLociRegistryComponent.generated.h"

/**
 * UAshenCognitiveLociRegistryComponent
 * 
 * Manages mental anchor nodes and memory graph loci unlocked in Whisperwood.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCognitiveLociRegistryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCognitiveLociRegistryComponent();

	/** Gets canonical descriptive text for a discovered cognitive locus */
	UFUNCTION(BlueprintPure, Category = "Ashen|Scenario4")
	FText GetLocusDescription(const FName& LocusId) const;
};
