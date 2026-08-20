// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenStateTreeEvaluateActionTask.h"
#include "GameFramework/Actor.h"

UAshenStateTreeEvaluateActionTask::UAshenStateTreeEvaluateActionTask()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenStateTreeEvaluateActionTask::BeginPlay()
{
	Super::BeginPlay();
}

float UAshenStateTreeEvaluateActionTask::EvaluateActionUtility(AActor* TargetActor, float CurrentStamina)
{
	float Distance = TargetActor ? FVector::Dist(GetOwner()->GetActorLocation(), TargetActor->GetActorLocation()) : PreferredRange;
	float RangeFactor = FMath::Clamp(1.0f - (FMath::Abs(Distance - PreferredRange) / PreferredRange), 0.1f, 1.0f);
	float StaminaFactor = FMath::Clamp(CurrentStamina / 100.0f, 0.2f, 1.0f);

	CalculatedUtility = BaseUtility * RangeFactor * StaminaFactor;
	UE_LOG(LogTemp, Log, TEXT("UAshenStateTreeEvaluateActionTask: Evaluated action utility for %s (Calculated: %f)"), *ActionTypeTag.ToString(), CalculatedUtility);
	return CalculatedUtility;
}
