// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "GameplayTagContainer.h"
#include "Soul/AshenSoulTypes.h"
#include "AshenSoulPublisher.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSoulStateCommitted, const FSoulStateVector&, NewState, const FSomaticState&, SomaticState);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRelationalMatrixUpdated, const FRelationalMatrix_V2&, NewMatrix);

USTRUCT(BlueprintType)
struct FAshenStateDeltaBuffer
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|State")
	float ResolveDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|State")
	float CorruptionDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|State")
	float IntegrationDebtDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|State")
	float GarrettRelianceDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|State")
	float SerafinaConfidenceDelta = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|State")
	FGameplayTag NewStanceTag = FGameplayTag::EmptyTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	bool bHasPendingMutations = false;

	bool HasRelationalDelta() const
	{
		return !FMath::IsNearlyZero(GarrettRelianceDelta) || !FMath::IsNearlyZero(SerafinaConfidenceDelta);
	}

	void Reset()
	{
		ResolveDelta = 0.0f;
		CorruptionDelta = 0.0f;
		IntegrationDebtDelta = 0.0f;
		GarrettRelianceDelta = 0.0f;
		SerafinaConfidenceDelta = 0.0f;
		NewStanceTag = FGameplayTag::EmptyTag;
		bHasPendingMutations = false;
	}
};

USTRUCT(BlueprintType)
struct FAshenStateSnapshot
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	int64 StateVersion = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	int64 TransactionId = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	float Resolve = 0.5f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	float Corruption = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	float IntegrationDebt = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	float GameplayEffectiveMass = 66.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	FGameplayTag ActiveStanceTag = FGameplayTag::EmptyTag;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen|State")
	int32 SchemaHash = (int32)0x9B4F1103;
};

UINTERFACE(MinimalAPI, Blueprintable)
class UAshenRelationalBridge : public UInterface { GENERATED_BODY() };

class ASHENOATH_API IAshenRelationalBridge
{
	GENERATED_BODY()

public:
	/** Validates whether the narrative relational sink is available to accept deltas */
	virtual bool CanAcceptRelationalDelta() const = 0;

	/** Commits relational deltas across the ImprintBuffer bridge */
	virtual void DispatchRelationalDelta(float GarrettRelianceDelta, float SerafinaConfidenceDelta) = 0;
};

UINTERFACE(MinimalAPI, Blueprintable)
class UAshenStateConsumer : public UInterface { GENERATED_BODY() };

class ASHENOATH_API IAshenStateConsumer
{
	GENERATED_BODY()

public:
	/** Immutable read-only snapshot broadcast receiver */
	UFUNCTION(BlueprintNativeEvent, Category = "Ashen|StateContract")
	void OnStateSnapshotCommitted(const FAshenStateSnapshot& Snapshot);
};

/**
 * UAshenSoulPublisher
 * Constitutional Law I: The Single Source of Truth (SSoT).
 * Subsystems are strictly prohibited from maintaining private meters or progression floats.
 * All persistent state mutations route atomically through CommitState / CommitStateDirect / CommitBufferedTransaction.
 * (PRS-001-SRC-CDTC-002)
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenSoulPublisher : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Pure handling mass derivation: Base: 80.0 kg. Floor: 45.0 kg. Ceiling: 120.0 kg. */
	UFUNCTION(BlueprintPure, Category = "Ashen|State")
	static float CalculateGameplayEffectiveMass(float IntegrationDebt, float Corruption, float Resolve);

	/** Stages 1-5 Intent Buffering */
	UFUNCTION(BlueprintCallable, Category = "Ashen|StateTransaction")
	void BufferStateDelta(float InResolveDelta, float InCorruptionDelta, float InDebtDelta, float InGarrettDelta, float InSerafinaDelta, FGameplayTag InStanceTag);

	/** Stage 6 Two-Phase Atomic Commit Boundary */
	UFUNCTION(BlueprintCallable, Category = "Ashen|StateTransaction")
	bool CommitBufferedTransaction();

	UFUNCTION(BlueprintPure, Category = "Ashen|StateTransaction")
	const FAshenStateSnapshot& GetAuthoritativeSnapshot() const { return CurrentSnapshot; }

	UFUNCTION(BlueprintCallable, Category = "Ashen|StateTransaction")
	void RegisterConsumer(TScriptInterface<IAshenStateConsumer> Consumer);

	UFUNCTION(BlueprintCallable, Category = "Ashen|StateTransaction")
	void SetRelationalBridge(TScriptInterface<IAshenRelationalBridge> Bridge);

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
	FAshenStateSnapshot CurrentSnapshot;
	FAshenStateDeltaBuffer ActiveDeltaBuffer;
	int64 NextTransactionId = 1;
	bool bIsBroadcasting = false;

	UPROPERTY()
	TArray<TScriptInterface<IAshenStateConsumer>> RegisteredConsumers;

	UPROPERTY()
	TScriptInterface<IAshenRelationalBridge> RelationalBridge;

	void PublishStateUpdate();
	void BroadcastSnapshot();
};
