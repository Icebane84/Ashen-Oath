// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenWhiteFlameAIDirectorComponent.h"

UAshenWhiteFlameAIDirectorComponent::UAshenWhiteFlameAIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenWhiteFlameAIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenWhiteFlameAIDirectorComponent::SynchronizeCatharsisAI(bool bIsWhiteFlameActive)
{
	if (bIsWhiteFlameActive)
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenWhiteFlameAIDirectorComponent: CATHARSIS AI SYNC ACTIVE -> Garrett guarding rear perimeter while Serafina anchors White Flame!"));
	}
}
