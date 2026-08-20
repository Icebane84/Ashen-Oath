// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenStaggerStateEvaluatorComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyStaggeredStateChanged, bool, bIsStaggered);

/**
 * UAshenStaggerStateEvaluatorComponent
 * Component tracking enemy poise breaking and opening execution windows (3.0s).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenStaggerStateEvaluatorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenStaggerStateEvaluatorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnEnemyStaggeredStateChanged OnStaggeredStateChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	bool bIsStaggeredForExecution = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	void TriggerExecutionStaggerWindow(float DurationSeconds = 3.0f);
};
