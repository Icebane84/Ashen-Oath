// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Soul/AshenIdentityCompilerComponent.h"

UAshenIdentityCompilerComponent::UAshenIdentityCompilerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenIdentityCompilerComponent::BeginPlay() { Super::BeginPlay(); }

FSoulStateVector UAshenIdentityCompilerComponent::CompileIdentity(
	float SanityRatio,
	float InstabilityScore,
	float IsolationWeight,
	float InGarrettTrust,
	float InSerafinaTrust,
	EInterpretiveLens ActiveLens)
{
	FSoulStateVector CompiledVector;
	CompiledVector.Resolve = FMath::Clamp(SanityRatio, 0.0f, 1.0f);
	CompiledVector.Corruption = FMath::Clamp(InstabilityScore, 0.0f, 1.0f);
	CompiledVector.Isolation = FMath::Clamp(IsolationWeight, 0.0f, 1.0f);

	float GT = InGarrettTrust;
	float ST = InSerafinaTrust;

	if (ActiveLens == EInterpretiveLens::Accountability)
	{
		GT = FMath::Clamp(GT * 1.15f, 0.0f, 1.0f);
	}
	else if (ActiveLens == EInterpretiveLens::Grace)
	{
		ST = FMath::Clamp(ST * 1.15f, 0.0f, 1.0f);
	}

	CompiledVector.GarrettTrust = GT;
	CompiledVector.SerafinaTrust = ST;

	UE_LOG(LogTemp, Warning, TEXT("UAshenIdentityCompilerComponent: Identity Compiled -> Resolve: %.2f, Corruption: %.2f, Isolation: %.2f, GTrust: %.2f, STrust: %.2f"),
		CompiledVector.Resolve, CompiledVector.Corruption, CompiledVector.Isolation, CompiledVector.GarrettTrust, CompiledVector.SerafinaTrust);

	return CompiledVector;
}
