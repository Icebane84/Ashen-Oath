// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenSerafinaHealPrioritizationEvaluatorComponent.h"

UAshenSerafinaHealPrioritizationEvaluatorComponent::UAshenSerafinaHealPrioritizationEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

AActor* UAshenSerafinaHealPrioritizationEvaluatorComponent::EvaluateHealTarget(AActor* KaelenActor, AActor* GarrettActor, float KaelenHealthPct, float GarrettHealthPct, float SerafinaTrustInKaelen)
{
	float KaelenPriority = (1.0f - KaelenHealthPct) * (0.5f + (SerafinaTrustInKaelen * 0.5f));
	float GarrettPriority = (1.0f - GarrettHealthPct);

	AActor* Target = (KaelenPriority >= GarrettPriority) ? KaelenActor : GarrettActor;
	UE_LOG(LogTemp, Log, TEXT("UAshenSerafinaHealPrioritizationEvaluatorComponent: Serafina heal target evaluated. Priority (Kaelen: %.2f, Garrett: %.2f)"), KaelenPriority, GarrettPriority);
	return Target;
}
