// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenShroudKnightTypes.h"
#include "AshenShroudKnightMasterBridge.generated.h"

/**
 * UAshenShroudKnightMasterBridge
 * 
 * Master orchestrator bridging the Shroud-Knight boss encounter subsystem, paranoia shaders, AI StateTree, and Trinity Strike GAS abilities.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenShroudKnightMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenShroudKnightMasterBridge();

	/** Broadcasts live boss telemetry */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Boss")
	void BroadcastBossState(const FShroudKnightBossVector& NewState);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Boss")
	FOnParanoiaInfectionChanged OnParanoiaBroadcaster;
};
