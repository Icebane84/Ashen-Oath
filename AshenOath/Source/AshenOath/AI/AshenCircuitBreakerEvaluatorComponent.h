// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCircuitBreakerEvaluatorComponent.generated.h"

/**
 * UAshenCircuitBreakerEvaluatorComponent
 * Evaluates character utility scores (LAW-001 Circuit Breaker Protocol). If utility < 0.15f, AI behavior trees trip into high-aggression exploit modes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCircuitBreakerEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCircuitBreakerEvaluatorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | AI")
	float CircuitBreakerThreshold = 0.15f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	bool ShouldTripCircuitBreaker(float CharacterUtilityScore) const;
};
