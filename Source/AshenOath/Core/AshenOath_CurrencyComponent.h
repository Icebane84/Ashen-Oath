// AshenOath_CurrencyComponent.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON) & Pillar III (Ember and Ash Economy)
// Primary resource economy -- Embers (session-volatile) and Ash (permanent integration currency).
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOath_CurrencyComponent.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAshenCurrency, Log, All);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCurrencyChangedSignature, float, CurrentEmbers, float, CurrentAsh);

/**
 * @class UAshenOath_CurrencyComponent
 * @brief Resource economy component attached to AAshenCombatCharacter.
 *
 * Embers: session-volatile currency earned from combat/loot. Lost on death before Heartstone.
 * Ash: permanent currency earned from InvokeIntegration() proportional to StateVector.Resolve. Never lost on death.
 */
UCLASS(ClassGroup = (AshenOath), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_CurrencyComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_CurrencyComponent();

	// --- Ember API (Session Volatile) ---------------------------------------

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Currency")
	void AddEmbers(float Amount);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Currency")
	bool DeductEmbers(float Amount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Currency")
	float GetEmbers() const { return Embers; }

	/** Called on pre-Heartstone death. Drops active Embers to 0 and returns the amount lost (for Ember Echo actor). */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Currency")
	float DropEmbersOnDeath();

	// --- Ash API (Permanent Integration Currency) ----------------------------

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Currency")
	void AddAsh(float Amount);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Currency")
	bool DeductAsh(float Amount);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Currency")
	float GetAsh() const { return Ash; }

	/** Called by Soul Constellation Kernel during FinalizeIntegration(). */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Currency")
	void GrantAshOnIntegration(float BaseGrant, float ResolveMultiplier);

	// --- Save/Load API ------------------------------------------------------

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Currency")
	void LoadCurrencyState(float SavedEmbers, float SavedAsh);

	// --- Delegates ----------------------------------------------------------

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Currency|Events")
	FOnCurrencyChangedSignature OnCurrencyChanged;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(SaveGame, VisibleAnywhere, Category = "AshenOath|Currency")
	float Embers = 0.0f;

	UPROPERTY(SaveGame, VisibleAnywhere, Category = "AshenOath|Currency")
	float Ash = 0.0f;
};
