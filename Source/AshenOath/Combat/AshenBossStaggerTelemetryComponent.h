// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenBossIncursionTypes.h"
#include "AshenBossStaggerTelemetryComponent.generated.h"

/**
 * UAshenBossStaggerTelemetryComponent
 * Tracks boss poise depletion, activates the 0.75s Trial of Will execution window, and registers Tripartite Finisher readiness.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossStaggerTelemetryComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossStaggerTelemetryComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	float StaggerWindowRemainingSeconds = 0.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Boss")
	bool bIsStaggerWindowOpen = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	void OpenStaggerWindow(float Duration = 0.75f);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Boss")
	bool ExecuteStaggerFinisher(EStaggerExecutionType FinisherType, float& OutExecutionDamage);
};
