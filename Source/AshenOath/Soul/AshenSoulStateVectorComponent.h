// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulStateVectorComponent.generated.h"

/**
 * FSoulStateVector
 *
 * Immutable psychological and physical state vector defined in UMB-SYS-005.
 * Tracks Health, Stamina, Sanity, Poise, Corruption, Integration Debt, and Unchained Vessel state.
 */
USTRUCT(BlueprintType)
struct ASHENOATH_API FAshenSoulStateVector
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulState")
	float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulState")
	float Stamina = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulState")
	float Sanity = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulState")
	float Poise = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulState")
	float CorruptionLevel = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulState")
	float IntegrationDebt = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulState")
	float UnchainedVesselLevel = 0.0f;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSoulStateVectorUpdatedSignature, const FAshenSoulStateVector&, NewSoulVector);

/**
 * UAshenSoulStateVectorComponent
 *
 * Core component managing Kaelen's FSoulStateVector as mandated by UMB-SYS-005.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulStateVectorComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulStateVectorComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SoulState")
	void UpdateSoulVector(const FAshenSoulStateVector& InVector);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SoulState")
	void AccumulateIntegrationDebt(float DebtDelta);

	UFUNCTION(BlueprintPure, Category = "AshenOath|SoulState")
	const FAshenSoulStateVector& GetSoulVector() const { return CurrentSoulVector; }

	UFUNCTION(BlueprintPure, Category = "AshenOath|SoulState")
	float GetIntegrationDebt() const { return CurrentSoulVector.IntegrationDebt; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SoulState|Events")
	FOnSoulStateVectorUpdatedSignature OnSoulStateVectorUpdated;

private:
	FAshenSoulStateVector CurrentSoulVector;
};


