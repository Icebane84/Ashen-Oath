// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "World/AshenDynamicRubbleTypes.h"
#include "AshenRubblePhysicsMasterBridge.generated.h"

/**
 * UAshenRubblePhysicsMasterBridge
 * 
 * Master orchestrator connecting Chaos destruction physics, falling hazard telegraphs, demolition abilities, and AI hazard avoidance.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenRubblePhysicsMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenRubblePhysicsMasterBridge();

	/** Broadcasts live hazard telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Rubble")
	void BroadcastHazardState(const FMasonryHazardVector& HazardState);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Rubble")
	FOnFallingHazardTelegraphed OnHazardBroadcaster;
};
