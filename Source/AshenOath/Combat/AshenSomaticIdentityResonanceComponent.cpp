// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenSomaticIdentityResonanceComponent.h"

UAshenSomaticIdentityResonanceComponent::UAshenSomaticIdentityResonanceComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticIdentityResonanceComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenSomaticIdentityResonanceComponent::UpdateIdentityResonance(float DeltaResonance)
{
	IdentityResonanceScalar = FMath::Clamp(IdentityResonanceScalar + DeltaResonance, 0.0f, 2.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticIdentityResonanceComponent: Identity resonance scalar updated to %f"), IdentityResonanceScalar);
}
