// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "UI/AshenCombatStancePostProcessAdapter.h"

UAshenCombatStancePostProcessAdapter::UAshenCombatStancePostProcessAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenCombatStancePostProcessAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenCombatStancePostProcessAdapter::ApplyStanceVisualGrading(ECombatStance Stance)
{
	FString Grade = TEXT("Flow Ethereal Lens Flare");
	if (Stance == ECombatStance::Aegis) Grade = TEXT("Aegis Cool Steel Desaturation");
	else if (Stance == ECombatStance::Berserk) Grade = TEXT("Berserk Radial Speed Blur");

	UE_LOG(LogTemp, Log, TEXT("UAshenCombatStancePostProcessAdapter: Applied '%s' visual grading."), *Grade);
}
