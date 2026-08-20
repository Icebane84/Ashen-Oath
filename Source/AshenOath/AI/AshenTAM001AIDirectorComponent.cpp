// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "AI/AshenTAM001AIDirectorComponent.h"

UAshenTAM001AIDirectorComponent::UAshenTAM001AIDirectorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTAM001AIDirectorComponent::BeginPlay() { Super::BeginPlay(); }

float UAshenTAM001AIDirectorComponent::CalculateCompanionDefensiveSpacing(float ConsistencyScore) const
{
	// High consistency brings companions into tight protective diamond (250uu); low consistency widens spacing to 500uu
	const float Spacing = FMath::Lerp(500.0f, 250.0f, FMath::Clamp(ConsistencyScore, 0.0f, 1.0f));
	return Spacing;
}
