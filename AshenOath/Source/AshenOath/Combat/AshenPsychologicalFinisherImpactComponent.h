// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenPsychologicalFinisherImpactComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnDebtReductionApplied, float, ReductionAmount);

/**
 * UAshenPsychologicalFinisherImpactComponent
 * Component calculating Integration Debt reduction (-0.15) upon executing staggered foes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenPsychologicalFinisherImpactComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenPsychologicalFinisherImpactComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnDebtReductionApplied OnDebtReductionApplied;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Combat")
	float ExecutionDebtReductionValue = 0.15f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	float ProcessExecutionDebtReduction();
};
