// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenBladeSanityMasterBridge.generated.h"

/**
 * UAshenBladeSanityMasterBridge
 * 
 * Master orchestrator bridging the Oathbringer blade subsystem, sanity component, Quartz music conductor, and somatic HUD widgets.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBladeSanityMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBladeSanityMasterBridge();

	/** Broadcasts live convergence update across all listener domains */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Convergence")
	void BroadcastConvergenceState(float BladeHunger01, float CurrentSanity);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Convergence")
	FOnBladeHungerSanityShifted OnConvergenceBroadcaster;
};
