// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenTripartiteResourceEconomyComponent.h"

UAshenTripartiteResourceEconomyComponent::UAshenTripartiteResourceEconomyComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentState.KaelenCorruption = 0.0f;
	CurrentState.SerafinaBurnout = 0.0f;
	CurrentState.GarrettSanityPosture = 1.0f;
}
void UAshenTripartiteResourceEconomyComponent::BeginPlay() { Super::BeginPlay(); }

void UAshenTripartiteResourceEconomyComponent::ApplyGlassShieldOverextension(float DamageAbsorbed)
{
	CurrentState.KaelenCorruption = FMath::Clamp(CurrentState.KaelenCorruption + (DamageAbsorbed * 0.001f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("UAshenTripartiteResourceEconomyComponent: Glass Shield Overextended! Kaelen Corruption: %.2f"),
		CurrentState.KaelenCorruption);
}

void UAshenTripartiteResourceEconomyComponent::ApplyTransferenceHealing(float HealthMended)
{
	CurrentState.SerafinaBurnout = FMath::Clamp(CurrentState.SerafinaBurnout + (HealthMended * 0.0015f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("UAshenTripartiteResourceEconomyComponent: Transference Applied! Serafina Burnout: %.2f"),
		CurrentState.SerafinaBurnout);
}

void UAshenTripartiteResourceEconomyComponent::ApplySentinelPostureLoss(float PostureDamage)
{
	CurrentState.GarrettSanityPosture = FMath::Clamp(CurrentState.GarrettSanityPosture - (PostureDamage * 0.01f), 0.0f, 1.0f);
	UE_LOG(LogTemp, Warning, TEXT("UAshenTripartiteResourceEconomyComponent: Sentinel Posture Loss! Garrett Sanity: %.2f"),
		CurrentState.GarrettSanityPosture);
}
