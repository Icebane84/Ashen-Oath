// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 798: Ashen Oathbringer Three Stage Lifecycle Component

#include "AshenOathbringerThreeStageLifecycleComponent.h"

UAshenOathbringerThreeStageLifecycleComponent::UAshenOathbringerThreeStageLifecycleComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentLifecycleStage = FName(TEXT("Stage.Dormant"));
}

void UAshenOathbringerThreeStageLifecycleComponent::SetOathbringerLifecycleStage(FName StageTag)
{
	CurrentLifecycleStage = StageTag;
	float VelocityMult = 1.0f;

	if (CurrentLifecycleStage.IsEqual(FName(TEXT("Stage.Predictive"))))
	{
		VelocityMult = 1.25f;
	}
	else if (CurrentLifecycleStage.IsEqual(FName(TEXT("Stage.Autonomous"))))
	{
		VelocityMult = 1.60f;
	}

	OnLifecycleStageChanged.Broadcast(CurrentLifecycleStage, VelocityMult);

	UE_LOG(LogTemp, Warning, TEXT("UAshenOathbringerThreeStageLifecycleComponent: LIFECYCLE STAGE CHANGED -> Stage: '%s' | Velocity Mult: %.2fx."),
		*CurrentLifecycleStage.ToString(), VelocityMult);
}
