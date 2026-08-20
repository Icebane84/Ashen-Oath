// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenCanonicalStateRegistryComponent.generated.h"

/**
 * UAshenCanonicalStateRegistryComponent
 * 
 * Single authoritative container on the Player State holding FCanonicalSoulStateVector and FCanonicalRelationalMatrix.
 * Validates Invariants 1 through 7 before committing any state mutations and stamping monotonic StateVersions.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCanonicalStateRegistryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCanonicalStateRegistryComponent();

	virtual void BeginPlay() override;

	/** Attempts to commit a soul compilation result after strict invariant validation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|StateRegistry")
	bool CommitCompilationResult(const FCompilationResult& CompilationResult, FGuid& OutTransactionId);

	/** Direct authoritative commit for scripted story beats / irreversible mutations */
	UFUNCTION(BlueprintCallable, Category = "Ashen|StateRegistry")
	bool CommitDirectStateMutation(
		const FCanonicalSoulStateVector& NewSoulState,
		const FCanonicalRelationalMatrix& NewRelationalMatrix,
		const FGameplayTagContainer& AuthorizationTags,
		FGuid& OutTransactionId);

	/** Broadcast delegate when state is successfully committed */
	UPROPERTY(BlueprintAssignable, Category = "Ashen|StateRegistry")
	FOnCanonicalStateCommitted OnCanonicalStateCommitted;

	UFUNCTION(BlueprintPure, Category = "Ashen|StateRegistry")
	const FCanonicalSoulStateVector& GetSoulState() const { return CurrentSoulState; }

	UFUNCTION(BlueprintPure, Category = "Ashen|StateRegistry")
	const FCanonicalRelationalMatrix& GetRelationalMatrix() const { return CurrentRelationalMatrix; }

	UFUNCTION(BlueprintPure, Category = "Ashen|StateRegistry")
	int64 GetStateVersion() const { return CurrentSoulState.StateVersion; }

	/** Validates Invariants 1 through 7 against proposed target states */
	UFUNCTION(BlueprintPure, Category = "Ashen|StateRegistry")
	bool ValidateInvariants(
		const FCanonicalSoulStateVector& ProposedSoul,
		const FCanonicalRelationalMatrix& ProposedRelational,
		const FGameplayTagContainer& TransactionTags,
		bool bIsDebtReduction) const;

private:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|StateRegistry")
	FCanonicalSoulStateVector CurrentSoulState;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|StateRegistry")
	FCanonicalRelationalMatrix CurrentRelationalMatrix;

	UPROPERTY(VisibleAnywhere, Category = "Ashen|StateRegistry")
	TArray<FGuid> CommittedTransactionHistory;
};
