// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBladeSanityConductorTypes.h"
#include "AshenFlowStateCatharsisDirectorComponent.generated.h"

/**
 * UAshenFlowStateCatharsisDirectorComponent
 * 
 * Coordinates the 8.0-second Symbiotic Flow State window, purging +40 sanity, doubling stamina recovery, and muting Eldrin whispers.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFlowStateCatharsisDirectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenFlowStateCatharsisDirectorComponent();

	/** Gets active Flow State duration in seconds */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Flow")
	float GetFlowStateDurationSeconds() const { return 8.0f; }

	/** Gets flow state stamina recovery multiplier [2.0x] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Flow")
	float GetFlowStaminaRegenMultiplier() const { return 2.0f; }

	/** Gets instant sanity catharsis restoration amount [+40.0] */
	UFUNCTION(BlueprintPure, Category = "Ashen|Convergence|Flow")
	float GetInstantSanityCatharsisAmount() const { return 40.0f; }
};
