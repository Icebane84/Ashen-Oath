// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Companions/AshenCampfireMarginaliaTypes.h"
#include "Orchestration/AshenMacroSystemicContractTypes.h"
#include "AshenCompanionMarginaliaEvaluatorComponent.generated.h"

class UAshenMarginaliaSpatialLayoutEngine;
class UAshenDeterministicMarginaliaFallbackProvider;
class UAshenMarginaliaProvenanceValidator;

/**
 * UAshenCompanionMarginaliaEvaluatorComponent
 * 
 * Evaluates soul state vectors and recent memory imprints at campfires to generate
 * multi-authored marginalia entries with spatial collision prevention.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionMarginaliaEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionMarginaliaEvaluatorComponent();

	virtual void BeginPlay() override;

	/** Evaluates campfire rest to produce companion annotations */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Marginalia")
	TArray<FMarginaliaEntry> EvaluateCampfireMarginalia(
		const FCanonicalSoulStateVector& CurrentSoulState,
		const TArray<FString>& ActiveImprints);

	/** Evaluates marginalia using legacy FSoulStateVector */
	UFUNCTION(BlueprintCallable, Category = "Ashen|Journal|Marginalia")
	void EvaluateMarginalia(const struct FSoulStateVector& State);

	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Marginalia")
	FString GetActiveGarrettMarginalia() const { return CachedGarrettMarginalia; }

	UFUNCTION(BlueprintPure, Category = "Ashen|Journal|Marginalia")
	FString GetActiveSerafinaMarginalia() const { return CachedSerafinaMarginalia; }

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Journal|Marginalia")
	FOnMarginaliaBatchGenerated OnMarginaliaBatchGenerated;

	UPROPERTY(BlueprintAssignable, Category = "Ashen|Journal|Marginalia")
	FOnMarginaliaCrossoutApplied OnMarginaliaCrossoutApplied;

protected:
	FString CachedGarrettMarginalia;
	FString CachedSerafinaMarginalia;

protected:
	UPROPERTY()
	UAshenMarginaliaSpatialLayoutEngine* LayoutEngine;

	UPROPERTY()
	UAshenDeterministicMarginaliaFallbackProvider* FallbackProvider;

	UPROPERTY()
	UAshenMarginaliaProvenanceValidator* ProvenanceValidator;
};
