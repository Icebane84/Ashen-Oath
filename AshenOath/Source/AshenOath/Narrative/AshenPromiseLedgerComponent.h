// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCanonicalPromiseTypes.h"
#include "AshenPromiseLedgerComponent.generated.h"

/**
 * UAshenPromiseLedgerComponent
 * 
 * Stores all canonical promises, managing status updates and querying.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPromiseLedgerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenPromiseLedgerComponent();

	/** Registers a new promise */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Promise")
	FCanonicalPromiseRecord RegisterPromise(
		FName TargetCompanion,
		const FString& PromiseText,
		EPromiseDomainScope Scope,
		FGameplayTag ContextTag);

	/** Updates status of existing promise */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Narrative|Promise")
	bool UpdatePromiseStatus(const FString& PromiseId, EPromiseResolutionStatus NewStatus);

	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Promise")
	TArray<FCanonicalPromiseRecord> GetActivePromises() const;

	UFUNCTION(BlueprintPure, Category = "Ashen|Narrative|Promise")
	int32 GetTotalPromiseCount() const { return PromiseStore.Num(); }

protected:
	UPROPERTY(VisibleAnywhere, Category = "Ashen|Narrative|Promise")
	TArray<FCanonicalPromiseRecord> PromiseStore;
};
