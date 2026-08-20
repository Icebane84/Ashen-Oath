// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenCognitiveComponent.h"
#include "Engine/World.h"

UAshenCognitiveComponent::UAshenCognitiveComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCognitiveComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCognitiveComponent::RecordActionExecution(FGameplayTag ActionTag)
{
	float CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
	ActionUsageTimestamps.FindOrAdd(ActionTag).Add(CurrentTime);
	UE_LOG(LogTemp, Log, TEXT("UAshenCognitiveComponent: Recorded action execution for tag %s at timestamp %f"), *ActionTag.ToString(), CurrentTime);
}

int32 UAshenCognitiveComponent::GetRecentActionUsageCount(FGameplayTag ActionTag, float WindowSeconds) const
{
	if (!ActionUsageTimestamps.Contains(ActionTag))
	{
		return 0;
	}

	float CurrentTime = GetWorld() ? GetWorld()->GetTimeSeconds() : 0.0f;
	int32 Count = 0;
	for (float Timestamp : ActionUsageTimestamps[ActionTag])
	{
		if (CurrentTime - Timestamp <= WindowSeconds)
		{
			Count++;
		}
	}
	return Count;
}
