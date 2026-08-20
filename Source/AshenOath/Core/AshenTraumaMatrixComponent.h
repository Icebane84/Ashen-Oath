// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathTrustTypes.h"
#include "AshenTraumaMatrixComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnTraumaDisruptionEvaluatedSignature, EAshenOathCompanion, TargetCompanion, FString, AdversarialArgument, float, ResourceDisruptionMagnitude);

/**
 * UAshenTraumaMatrixComponent
 *
 * Implements PAA V2.0 Trauma Enemy Matrix.
 * Anchors enemy AI combat behavior directly to targeted psychological trauma vectors
 * for Kaelen, Garrett, and Serafina.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaMatrixComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTraumaMatrixComponent();

protected:
	virtual void BeginPlay() override;

public:
	// --- Trauma Parameters ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|TraumaMatrix")
	EAshenOathCompanion TargetVector = EAshenOathCompanion::Kaelen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|TraumaMatrix")
	FString AdversarialArgument = TEXT("Preparation is an illusion");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|TraumaMatrix")
	float DisruptionMultiplier = 1.5f;

	// --- Actions ---

	/** Evaluates psychological trauma disruption against target companion. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|TraumaMatrix")
	void EvaluateTraumaDisruption(AActor* TargetActor);

	/** Forces trauma expenditure, driving resource cost to the targeted companion. */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|TraumaMatrix")
	void ApplyTraumaExpenditure(AActor* TargetActor, float RawToll);

	// --- Events ---
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|TraumaMatrix|Events")
	FOnTraumaDisruptionEvaluatedSignature OnTraumaDisruptionEvaluated;
};
