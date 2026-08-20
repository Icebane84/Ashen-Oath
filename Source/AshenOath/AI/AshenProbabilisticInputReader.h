// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenProbabilisticInputReader.generated.h"

/**
 * UAshenProbabilisticInputReader
 * AI component calculating P_react = P_base * (1 - phi_stamina) * omega_aggression * e^(-lambda * d) for stamina-gated, non-frame-perfect input reading.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenProbabilisticInputReader : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenProbabilisticInputReader();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Input Reading")
	float BaseProbability = 0.80f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Input Reading")
	float CalculateReactionProbability(float TargetDistance, float StaminaReserve, float AggressionWeight);
};
