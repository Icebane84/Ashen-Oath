// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenIntegrationDebtPipelineComponent.generated.h"

/**
 * UAshenIntegrationDebtPipelineComponent
 * Manages the 4-tier Integration Debt pressure ladder (Buffer 0-49%, Memory Bleed 50-74%, Runtime Noise 75-99%, Forced Integration 100%).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenIntegrationDebtPipelineComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenIntegrationDebtPipelineComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Soul")
	float CurrentIntegrationDebt = 0.0f; // 0.0 to 100.0%

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	EIntegrationDebtStage EvaluateDebtStage(float InDebt);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Soul")
	float CalculateParryWindowPenalty(float BaseWindowSeconds) const;
};
