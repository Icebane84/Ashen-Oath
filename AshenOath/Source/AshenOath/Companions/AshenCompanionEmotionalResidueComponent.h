// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionEmotionalResidueComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEmotionalResidueAccumulatedSignature, FName, CompanionID, float, TotalResidue);

/**
 * UAshenCompanionEmotionalResidueComponent
 *
 * Component tracking emotional residue during combat and projecting into 3 distinct layers:
 * Layer 1 (Combat): Finisher cooldown reduction.
 * Layer 2 (Dialogue): Companion comfort/concern voice barks.
 * Layer 3 (AI): Defensive position priority near Kaelen.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionEmotionalResidueComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionEmotionalResidueComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|EmotionalResidue")
	void AccumulateEmotionalResidue(FName CompanionID, float DeltaResidue);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|EmotionalResidue|Events")
	FOnEmotionalResidueAccumulatedSignature OnResidueAccumulated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|EmotionalResidue")
	float CalculatedTotalResidue = 0.0f;
};
