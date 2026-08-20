// AshenOath_OathRegistryComponent.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON) Section 1 & Pillar III
// Living Oaths System -- Tracks promises sworn, kept, and broken across the campaign.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_OathRegistryComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAshenOathRegistry, Log, All);

// ---------------------------------------------------------------------------
// OATH RECORD STRUCT
// Data container for an individual sworn oath.
// ---------------------------------------------------------------------------
USTRUCT(BlueprintType)
struct ASHENOATH_API FOathRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oath")
	FName OathID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oath")
	FText OathDescription;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oath")
	bool bFulfilled = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oath")
	bool bBroken = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Oath")
	float TimeSinceSworn = 0.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOathSwornSignature, const FOathRecord&, Oath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOathFulfilledSignature, const FOathRecord&, Oath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOathBrokenSignature, const FOathRecord&, Oath);

/**
 * @class UAshenOath_OathRegistryComponent
 * @brief Tracks living oaths, oath burden accumulation, and oath break consequences.
 *
 * Attached to AAshenCombatCharacter.
 * Oath breaks feed heavy Oath imprints to ImprintBuffer and dim Oathbringer emissives.
 * Oath fulfillments heal sanity and restore weapon resonance.
 */
UCLASS(ClassGroup = (AshenOath), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_OathRegistryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_OathRegistryComponent();

	// --- Public API ---------------------------------------------------------

	/** Swear a new oath. Adds to active registry and increases OathBurden. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Oath")
	bool SwearOath(FName OathID, FText Description);

	/** Mark an oath as fulfilled. Triggers sanity heal and positive imprint. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Oath")
	bool FulfillOath(FName OathID);

	/** Mark an oath as broken. Triggers mental damage, heavy imprint, and weapon dimming. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Oath")
	bool BreakOath(FName OathID);

	/** Get total count of broken oaths. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Oath")
	int32 GetBrokenOathCount() const;

	/** Get total count of active (unfulfilled & unbroken) oaths. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Oath")
	int32 GetActiveOathCount() const;

	/** Returns current OathBurden accumulator (0.0 to 1.0+). */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Oath")
	float GetOathBurden() const { return OathBurden; }

	/** Returns true if OathBurden >= 1.0 (forces Oath Burn state). */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Oath")
	bool IsOathBurnActive() const { return OathBurden >= 1.0f; }

	/** Access active registry for save/load serialization. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Oath")
	const TArray<FOathRecord>& GetOaths() const { return Oaths; }

	/** Load oath registry state from save game data. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Oath")
	void LoadOathState(const TArray<FOathRecord>& SavedOaths, float SavedBurden);

	// --- Delegates ----------------------------------------------------------

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Oath|Events")
	FOnOathSwornSignature OnOathSworn;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Oath|Events")
	FOnOathFulfilledSignature OnOathFulfilled;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Oath|Events")
	FOnOathBrokenSignature OnOathBroken;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(SaveGame, VisibleAnywhere, Category = "AshenOath|Oath")
	TArray<FOathRecord> Oaths;

	/** Accumulated burden per oath sworn. At 1.0 triggers Oath Burn state. */
	UPROPERTY(SaveGame, VisibleAnywhere, Category = "AshenOath|Oath")
	float OathBurden = 0.0f;

	/** Burden increment added per oath sworn. */
	UPROPERTY(EditDefaultsOnly, Category = "AshenOath|Oath")
	float BurdenPerOath = 0.1f;
};
