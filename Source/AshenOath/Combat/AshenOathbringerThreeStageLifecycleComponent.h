// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenOathbringerThreeStageLifecycleComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnOathbringerLifecycleStageChangedSignature, FName, NewLifecycleStage, float, HandlingVelocityMultiplier);

/**
 * UAshenOathbringerThreeStageLifecycleComponent
 *
 * Component managing Oathbringer's 3-stage lifecycle: Dormant (Baseline), Predictive (Disciplined/Flow), Autonomous (Shadow/Unchained) (PRS-001 Combat Blueprint V5.0).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerThreeStageLifecycleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerThreeStageLifecycleComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|OathbringerLifecycle")
	void SetOathbringerLifecycleStage(FName StageTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|OathbringerLifecycle|Events")
	FOnOathbringerLifecycleStageChangedSignature OnLifecycleStageChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|OathbringerLifecycle")
	FName CurrentLifecycleStage = FName(TEXT("Stage.Dormant"));
};
