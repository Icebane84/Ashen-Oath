// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenEmpathicNovaTypes.h"
#include "AshenEmpathicNovaTelemetryComponent.generated.h"

/**
 * UAshenEmpathicNovaTelemetryComponent
 * Evaluates real-time friction flow between Kaelen and Serafina, Integration Debt escalation, and Serafina burnout rate (>75%).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEmpathicNovaTelemetryComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEmpathicNovaTelemetryComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nova")
	float CurrentFrictionFlow = 0.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	float EvaluateFrictionFlow(float KaelenTraumaRate, float SerafinaTransferenceRate);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool IsInCriticalBurnout(float SerafinaBurnout) const;
};
