// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenCombatAudioComponent.h"
#include "AshenOath_HealthComponent.h"
#include "AshenCompanionAIComponent.h"
#include "GameFramework/Actor.h"

UAshenCombatAudioComponent::UAshenCombatAudioComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAshenCombatAudioComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAshenCombatAudioComponent::SetInCombat(bool bInCombat)
{
	bIsInCombat = bInCombat;
}

void UAshenCombatAudioComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* OwnerActor = GetOwner();
	if (!OwnerActor) return;

	float HPFrac = 1.0f;
	if (UAshenOath_HealthComponent* Health = OwnerActor->FindComponentByClass<UAshenOath_HealthComponent>())
	{
		HPFrac = Health->GetMaxHealth() > 0.f ? Health->GetCurrentHealth() / Health->GetMaxHealth() : 0.f;
	}

	float Corruption = 0.0f;
	bool bResonance = false;
	if (UAshenCompanionAIComponent* AI = OwnerActor->FindComponentByClass<UAshenCompanionAIComponent>())
	{
		bResonance = AI->bSymbioticResonanceActive;
	}

	UpdateStems(HPFrac, Corruption, bResonance);

	// Smoothly interpolate stem volumes
	float TargetRhythm = bIsInCombat ? 1.0f : 0.0f;
	float TargetMelody = bIsInCombat ? (1.0f - HPFrac) * 0.8f + 0.2f : 0.0f;
	float TargetCorruption = bIsInCombat ? Corruption : 0.0f;
	float TargetTriumph = bResonance ? 1.0f : 0.0f;

	RhythmStemVolume               = FMath::FInterpTo(RhythmStemVolume, TargetRhythm, DeltaTime, InterpSpeed);
	MelodyStemVolume               = FMath::FInterpTo(MelodyStemVolume, TargetMelody, DeltaTime, InterpSpeed);
	CorruptionDissonanceStemVolume = FMath::FInterpTo(CorruptionDissonanceStemVolume, TargetCorruption, DeltaTime, InterpSpeed);
	TriumphStemVolume              = FMath::FInterpTo(TriumphStemVolume, TargetTriumph, DeltaTime, InterpSpeed);

	OnStemsUpdated.Broadcast(RhythmStemVolume, MelodyStemVolume, CorruptionDissonanceStemVolume, TriumphStemVolume);
}

void UAshenCombatAudioComponent::UpdateStems(float CurrentHPFrac, float Corruption, bool bResonanceActive)
{
	UE_LOG(LogTemp, Verbose, TEXT("UAshenCombatAudioComponent: Stems — Rhythm: %.2f | Melody: %.2f | Dissonance: %.2f | Triumph: %.2f"),
		RhythmStemVolume, MelodyStemVolume, CorruptionDissonanceStemVolume, TriumphStemVolume);
}
