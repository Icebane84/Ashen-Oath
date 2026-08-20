// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 729: Ashen Serafina Empathic Support Priority Director

#include "AshenSerafinaEmpathicSupportPriorityDirector.h"

AActor* UAshenSerafinaEmpathicSupportPriorityDirector::SelectHighPriorityEmpathicTarget(TArray<AActor*> PartyMembers, float KaelenStainLevel, float GarrettStainLevel)
{
	if (PartyMembers.Num() == 0) return nullptr;

	AActor* Target = (KaelenStainLevel >= GarrettStainLevel) ? PartyMembers[0] : (PartyMembers.Num() > 1 ? PartyMembers[1] : PartyMembers[0]);
	const float Urgency = FMath::Max(KaelenStainLevel, GarrettStainLevel);

	OnEmpathicTargetSelected.Broadcast(Target, Urgency);

	UE_LOG(LogTemp, Warning, TEXT("UAshenSerafinaEmpathicSupportPriorityDirector: EMPATHIC SUPPORT TARGET SELECTED -> Companion: '%s' | Stain Urgency: %.1f%%."),
		*Target->GetName(), Urgency);

	return Target;
}
