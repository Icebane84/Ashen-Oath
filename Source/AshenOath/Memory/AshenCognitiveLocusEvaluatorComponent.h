// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCognitiveLocusEvaluatorComponent.generated.h"

/**
 * UAshenCognitiveLocusEvaluatorComponent
 * Evaluates psychic proximity to memory loci, coherence falloff (1.0 - Distance/MaxRadius), and trauma density score.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCognitiveLocusEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCognitiveLocusEvaluatorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	float MaxResonanceRadius = 1500.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	float CalculateResonanceIntensity(const FVector& PlayerLocation, const FVector& LocusLocation) const;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	float EvaluateTraumaDensity(int32 UnsealedTraumaCount, float BaselineInstability) const;
};
