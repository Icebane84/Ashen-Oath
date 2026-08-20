// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenBossIncursionAIDirectorComponent.generated.h"

/**
 * UAshenBossIncursionAIDirectorComponent
 * AI Director evaluating boss combat pacing, minion reinforcement spawns, and phase shift execution.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossIncursionAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossIncursionAIDirectorComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	void CoordinatePhaseBehaviors(EBossPhaseState CurrentPhase);
};
