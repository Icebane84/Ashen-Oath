// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenCognitiveTypes.h"
#include "AshenCognitiveComponent.generated.h"

/**
 * UAshenCognitiveComponent
 * Core AI Cognitive component storing action usage history, threat state, and stamina reserves for StateTree utility tasks.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCognitiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCognitiveComponent();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Cognitive")
	FOnCognitiveActionSelected OnCognitiveActionSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cognitive")
	float CurrentStaminaReserve = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cognitive")
	float AggressionWeight = 1.2f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cognitive")
	void RecordActionExecution(FGameplayTag ActionTag);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cognitive")
	int32 GetRecentActionUsageCount(FGameplayTag ActionTag, float WindowSeconds) const;

private:
	TMap<FGameplayTag, TArray<float>> ActionUsageTimestamps;
};
