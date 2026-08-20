// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 741: Ashen Integrative Memory Pass Compiler Component

#include "AshenIntegrativeMemoryPassCompilerComponent.h"

UAshenIntegrativeMemoryPassCompilerComponent::UAshenIntegrativeMemoryPassCompilerComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	IntegrationClarityPercent = 100.0f;
}

void UAshenIntegrativeMemoryPassCompilerComponent::ExecuteIntegrativeMemoryPass(int32 TargetNodesToAlign)
{
	IntegrationClarityPercent = FMath::Clamp(100.0f - (TargetNodesToAlign * 1.5f), 50.0f, 100.0f);
	OnIntegrativePassCompiled.Broadcast(TargetNodesToAlign, IntegrationClarityPercent);

	UE_LOG(LogTemp, Warning, TEXT("UAshenIntegrativeMemoryPassCompilerComponent: INTEGRATIVE PASS COMPILED -> Nodes Aligned: %d | Clarity: %.1f%%."),
		TargetNodesToAlign, IntegrationClarityPercent);
}
