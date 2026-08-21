// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCampfireHearthTypes.h"
#include "AshenCampfireHearthMasterBridge.generated.h"

/**
 * UAshenCampfireHearthMasterBridge
 * 
 * Master orchestrator connecting campfire rest sessions, living journal inspection,
 * ambient audio filtering, and SaveGame persistence.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireHearthMasterBridge : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCampfireHearthMasterBridge();

	/** Broadcasts rest started */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Hearth")
	void BroadcastRestStarted(const FCampfireIntegrationSnapshot& Snapshot);

	/** Broadcasts trait transmuted */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Orchestration|Hearth")
	void BroadcastTraumaTransmuted(const FString& TraitId, float BonusValue);

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Hearth")
	FOnCampfireRestStarted OnCampfireRestStarted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Orchestration|Hearth")
	FOnTraumaTransmuted OnTraumaTransmuted;
};
