// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 799: Ashen Aegis Glancing Deflection Component

#include "AshenAegisGlancingDeflectionComponent.h"

UAshenAegisGlancingDeflectionComponent::UAshenAegisGlancingDeflectionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	TotalPerfectParriesExecuted = 0;
}

bool UAshenAegisGlancingDeflectionComponent::ExecuteGlancingDeflection(AActor* AttackingEnemy)
{
	TotalPerfectParriesExecuted++;
	const float StaggerMag = 100.0f; // Heavy enemy stagger

	OnGlancingDeflectionExecuted.Broadcast(AttackingEnemy, StaggerMag);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAegisGlancingDeflectionComponent: GLANCING DEFLECTION (PERFECT PARRY) EXECUTED -> Enemy: '%s' | Stamina Cost: 0.0 | Stagger: %.0f."),
		AttackingEnemy ? *AttackingEnemy->GetName() : TEXT("None"), StaggerMag);

	return true;
}
