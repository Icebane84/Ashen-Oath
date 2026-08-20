// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanctuaryRestComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSanctuaryRestStartedSignature);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSanctuaryRestCompletedSignature, float, ConsolidatedDebt);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEmberEchoRetrievedSignature, float, RecoveredEmbers);

/**
 * UAshenSanctuaryRestComponent
 *
 * Sanctuary Haven resting and Ember Echo retrieval component.
 * Governs campfire rest sequences:
 *   - Restores HP, Stamina, Mana, and Sanity to 100% maximum
 *   - Consolidates unintegrated identity imprints on UAshenOath_ImprintBufferComponent
 *   - Retrieves lost Embers via UAshenOath_CurrencyComponent upon touching Ember Echoes
 *   - Triggers companion resting dialogues based on trust accumulation thresholds
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryRestComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuaryRestComponent();

protected:
	virtual void BeginPlay() override;

public:
	/** Initiates campfire rest sequence — heals player, consolidates imprints, fires rest events. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanctuary")
	bool InitiateRestSequence(AActor* PlayerPawn);

	/** Recovers lost Embers from an Ember Echo actor or death marker. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanctuary")
	float RetrieveEmberEcho(AActor* PlayerPawn, float LostEmbersAmount);

	/** Checks companion trust thresholds to trigger rest dialogue scenes. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Sanctuary")
	void CheckCompanionRestDialogueTriggers(AActor* PlayerPawn);

	// --- Delegates ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanctuary|Events")
	FOnSanctuaryRestStartedSignature OnRestStarted;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanctuary|Events")
	FOnSanctuaryRestCompletedSignature OnRestCompleted;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Sanctuary|Events")
	FOnEmberEchoRetrievedSignature OnEmberEchoRetrieved;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Sanctuary")
	bool bIsResting = false;
};
