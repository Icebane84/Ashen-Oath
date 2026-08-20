// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenJournalTypes.h"
#include "AshenMemoryReconciliationEngine.generated.h"

/**
 * UAshenMemoryReconciliationEngine
 * Component executing deferred mechanical (immutable engine fact) vs interpretive (contested trio perspective) reconciliation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryReconciliationEngine : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMemoryReconciliationEngine();

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Reconciliation")
	FJournalEvent ReconcileMemoryEvent(FName MemoryNodeID, FText CanonicalFact, const TArray<FJournalPerspective>& Perspectives);
};
