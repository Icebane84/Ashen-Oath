// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "Companions/AshenRelationalEcologyTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenRelationalEcologySubsystem.generated.h"

/**
 * UAshenRelationalEcologySubsystem
 * 
 * Central World Subsystem governing the Ecology of Fellowship:
 * - Computes the Deterministic Faith Equation for companion Costly Presence
 * - Maintains active repair matrices across Garrett and Serafina
 * - Coordinates wordless reconciliation triggers and living journal multi-author logs
 */
UCLASS(BlueprintType)
class ASHENOATH_API UAshenRelationalEcologySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UAshenRelationalEcologySubsystem();

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/** Evaluates whether companion executes costly presence based on faith equation */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Ecology")
	FAshenCostlyPresenceIntent EvaluateCostlyPresenceIntent(
		FName CompanionName,
		float CompanionTrust,
		float ImmediateThreat,
		const FAshenRepairMatrix& RepairHistory);

	/** Computes the Deterministic Faith Threshold */
	UFUNCTION(BlueprintPure, Category = "Ashen|Ecology")
	float CalculateFaithThreshold(float ImmediateThreat, float ActiveRepairVelocity) const;

	/** Adds a new multi-author margin entry to the shared journal */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Ecology")
	void AddMultiAuthorEntry(EAuthorIdentity Author, const FText& Text, FName MemorySiteId, float StainOpacity = 1.0f);

	/** Updates active repair matrix for specific companion */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Ecology")
	void UpdateRepairMatrix(FName CompanionName, const FAshenRepairMatrix& NewMatrix);

	/** Gets active repair matrix for companion */
	UFUNCTION(BlueprintPure, Category = "Ashen|Ecology")
	FAshenRepairMatrix GetRepairMatrix(FName CompanionName) const;

	/** Gets all multi-author journal entries */
	UFUNCTION(BlueprintPure, Category = "Ashen|Ecology")
	const TArray<FAshenMultiAuthorMarginEntry>& GetJournalEntries() const { return JournalEntries; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Ecology")
	FOnCostlyPresenceTriggered OnCostlyPresenceTriggered;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Ecology")
	FOnRelationalRuptureChanged OnRelationalRuptureChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Ecology")
	FOnWordlessReconciliationExecuted OnWordlessReconciliationExecuted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Ecology")
	FOnMultiAuthorEntryAdded OnMultiAuthorEntryAdded;

private:
	UPROPERTY()
	TMap<FName, FAshenRepairMatrix> CompanionRepairMatrices;

	UPROPERTY()
	TArray<FAshenMultiAuthorMarginEntry> JournalEntries;
};
