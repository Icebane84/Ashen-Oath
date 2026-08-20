// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenCompanionEmpathicStateEvaluator.h"

UAshenCompanionEmpathicStateEvaluator::UAshenCompanionEmpathicStateEvaluator()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCompanionEmpathicStateEvaluator::BeginPlay() { Super::BeginPlay(); }

FString UAshenCompanionEmpathicStateEvaluator::EvaluateEmpathicMood(float TrustLevel, float FatigueLevel, float DebtLevel)
{
	if (DebtLevel > 0.75f || FatigueLevel > 0.70f) CurrentMoodProfile = "Panicked";
	else if (TrustLevel < 0.35f) CurrentMoodProfile = "Resentful";
	else if (TrustLevel > 0.70f) CurrentMoodProfile = "Harmonious";
	else CurrentMoodProfile = "Calm";

	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionEmpathicStateEvaluator: Empathic mood evaluated to '%s'"), *CurrentMoodProfile);
	return CurrentMoodProfile;
}
