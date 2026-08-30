// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTrustAccumulationComponent.generated.h"

class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionTrustChangedSignature, FName, CompanionName, float, NewTrustScore);

/**
 * UAshenTrustAccumulationComponent
 *
 * Lightweight view adapter routing trust queries and deltas directly to
 * Constitutional Law I Single Source of Truth (UAshenSoulPublisher).
 * Eliminates private state maps and synchronizes with FSoulStateVector & FRelationalMatrix_V2.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrustAccumulationComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTrustAccumulationComponent();

	virtual void BeginPlay() override;

	/** Adds trust delta to canonical soul state via UAshenSoulPublisher */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Trust")
	void AddTrust(FName CompanionName, float TrustDelta);

	/** Queries normalized trust score (0.0 to 100.0) from UAshenSoulPublisher */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Trust")
	float GetTrustScore(FName CompanionName) const;

	/** Queries synergy damage multiplier from multi-dimensional relational matrix */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Trust")
	float GetSynergyDamageMultiplier(FName CompanionName) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Trust")
	float MaxTrustScore = 100.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Trust|Events")
	FOnCompanionTrustChangedSignature OnTrustChanged;

private:
	UAshenSoulPublisher* GetSoulPublisher() const;
};
