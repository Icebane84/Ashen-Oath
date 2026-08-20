// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenSemanticMentionEvaluatorComponent.h"

UAshenSemanticMentionEvaluatorComponent::UAshenSemanticMentionEvaluatorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	MaxMentionTriggerRadius = 800.0f;
}
void UAshenSemanticMentionEvaluatorComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenSemanticMentionEvaluatorComponent::EvaluateSemanticMention(const FVector& PlayerLocation, const FVector& SemanticTargetLocation, FName TopicID, float& OutProximityRatio) const
{
	const float Distance = FVector::Dist(PlayerLocation, SemanticTargetLocation);
	if (Distance > MaxMentionTriggerRadius || MaxMentionTriggerRadius <= 0.0f)
	{
		OutProximityRatio = 0.0f;
		return false;
	}

	OutProximityRatio = FMath::Clamp(1.0f - (Distance / MaxMentionTriggerRadius), 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSemanticMentionEvaluatorComponent: Triggered Semantic Mention for Topic '%s' (Distance: %.1fuu, Ratio: %.2f)"),
		*TopicID.ToString(), Distance, OutProximityRatio);

	return true;
}
