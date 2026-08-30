// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Soul/AshenSoulTypes.h"
#include "AshenSoulPublisher.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSoulStateCommitted, const FSoulStateVector&, NewState, const FSomaticState&, SomaticState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRelationalMatrixUpdated, const FRelationalMatrix_V2&, NewMatrix);

/**
 * UAshenSoulPublisher
 * Constitutional Law I: The Single Source of Truth (SSoT).
 * Subsystems are strictly prohibited from maintaining private meters or progression floats.
 * All persistent state mutations route atomically through CommitState / CommitStateDirect.
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSoulPublisher : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Atomically commits delta adjustments to the 28-byte canonical soul state */
	UFUNCTION(BlueprintCallable, Category = "Soul|Publisher")
	void CommitState(const FSoulStateVector& Delta);

	/** Atomically replaces the canonical soul state (used for saves/resets) */
	UFUNCTION(BlueprintCallable, Category = "Soul|Publisher")
	void CommitStateDirect(const FSoulStateVector& NewState);

	/** Updates the multi-dimensional companion relational matrix */
	UFUNCTION(BlueprintCallable, Category = "Soul|Publisher")
	void SetRelationalMatrix(const FRelationalMatrix_V2& NewMatrix);

	/** Accessor for the canonical 28-byte persistent state */
	UFUNCTION(BlueprintPure, Category = "Soul|Publisher")
	FSoulStateVector GetSoulState() const { return CurrentSoulState; }

	/** Accessor for the derived runtime somatic signals */
	UFUNCTION(BlueprintPure, Category = "Soul|Publisher")
	FSomaticState GetCurrentSomaticState() const { return CurrentSomaticState; }

	/** Accessor for the multi-dimensional relational matrix */
	UFUNCTION(BlueprintPure, Category = "Soul|Publisher")
	FRelationalMatrix_V2 GetRelationalMatrix() const { return CurrentRelationalMatrix; }

	/** Manually triggers a recalculation of derived somatic states */
	UFUNCTION(BlueprintCallable, Category = "Soul|Publisher")
	void RecalculateSomaticState();

	UPROPERTY(BlueprintAssignable, Category = "Soul|Publisher")
	FOnSoulStateCommitted OnSoulStateCommitted;

	UPROPERTY(BlueprintAssignable, Category = "Soul|Publisher")
	FOnRelationalMatrixUpdated OnRelationalMatrixUpdated;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Soul|Canonical")
	FSoulStateVector CurrentSoulState;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Soul|Relational")
	FRelationalMatrix_V2 CurrentRelationalMatrix;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Soul|Derived")
	FSomaticState CurrentSomaticState;

private:
	void PublishStateUpdate();
};
