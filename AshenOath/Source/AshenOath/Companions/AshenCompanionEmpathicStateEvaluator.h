// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionEmpathicStateEvaluator.generated.h"

/**
 * UAshenCompanionEmpathicStateEvaluator
 * Subsystem evaluating current empathic mood profiles (Calm, Panicked, Resentful, Harmonious).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionEmpathicStateEvaluator : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCompanionEmpathicStateEvaluator();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Companions")
	FString CurrentMoodProfile = "Harmonious";

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	FString EvaluateEmpathicMood(float TrustLevel, float FatigueLevel, float DebtLevel);
};
