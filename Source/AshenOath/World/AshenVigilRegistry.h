// AshenVigilRegistry.h
// Copyright Ashen Oath. All rights reserved.
// PHOENIX CODEX: ENGINE-SPEC-001 (DEFINITIVE CANON) & Pillar IV (Vigil System)
// Persistent multi-stage challenge and long-arc objective log subsystem.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenVigilRegistry.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAshenVigil, Log, All);

USTRUCT(BlueprintType)
struct ASHENOATH_API FVigilRecord
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vigil")
	FName VigilID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vigil")
	FText VigilTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vigil")
	FText Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vigil")
	int32 CurrentStage = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vigil")
	int32 TotalStages = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vigil")
	bool bCompleted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Vigil")
	float RewardAsh = 150.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVigilStageProgressedSignature, const FVigilRecord&, Vigil);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVigilCompletedSignature, const FVigilRecord&, Vigil);

/**
 * @class UAshenVigilRegistry
 * @brief GameInstanceSubsystem tracking multi-stage long-arc campaign Vigils.
 */
UCLASS()
class ASHENOATH_API UAshenVigilRegistry : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Register a new Vigil. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Vigil")
	bool RegisterVigil(FName VigilID, FText Title, FText Description, int32 TotalStages, float RewardAsh = 150.0f);

	/** Advance stage progress for a Vigil. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Vigil")
	bool ProgressVigil(FName VigilID);

	/** Access registered Vigils for save/load. */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Vigil")
	const TArray<FVigilRecord>& GetVigils() const { return Vigils; }

	/** Restore state from save game data. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Vigil")
	void LoadVigilState(const TArray<FVigilRecord>& SavedVigils);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Vigil|Events")
	FOnVigilStageProgressedSignature OnVigilStageProgressed;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Vigil|Events")
	FOnVigilCompletedSignature OnVigilCompleted;

private:
	UPROPERTY(Transient)
	TArray<FVigilRecord> Vigils;
};
