// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSomaticPhenotypeIntegratorComponent.h"

UAshenSomaticPhenotypeIntegratorComponent::UAshenSomaticPhenotypeIntegratorComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSomaticPhenotypeIntegratorComponent::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	EyeEmissiveScalar = FMath::Clamp(NewState.Corruption * 5.0f, 0.0f, 5.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSomaticPhenotypeIntegratorComponent: Integrated eye emissive scalar -> %.2f"), EyeEmissiveScalar);
}
