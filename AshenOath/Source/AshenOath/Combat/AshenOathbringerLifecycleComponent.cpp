// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenOathbringerLifecycleComponent.h"
#include "Soul/AshenSoulPublisher.h"
#include "Soul/AshenSoulStateVector.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenOathbringerLifecycleComponent::UAshenOathbringerLifecycleComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentTier = EOathbringerMetallurgicalTier::BurdenedIron;
	EffectiveMass = 120.0f;
	ForwardPullImpulse = 0.0f;

	// Baseline Tier 1 parameters
	MaterialParameters.Roughness = 0.65f;
	MaterialParameters.Metallic = 0.98f;
	MaterialParameters.AnisotropyAngle = 0.45f;
	MaterialParameters.LightAbsorptionRadius = 0.0f;
	MaterialParameters.ViscousSeepageNormalStrength = 0.0f;
	MaterialParameters.TapetumLucidumRetroreflection = 0.0f;
	MaterialParameters.EmissiveIntensity = 0.0f;

	AcousticProfile.AirHissFrequency = 1200.0f;
	AcousticProfile.FoleyGrindIntensity = 0.80f;
	AcousticProfile.SilverChimeDecaySeconds = 0.0f;
	AcousticProfile.VacuumSuctionVolume = 0.0f;
	AcousticProfile.bDeadAcousticIsolation = false;
}

void UAshenOathbringerLifecycleComponent::BeginPlay()
{
	Super::BeginPlay();
	EvaluateWeaponLifecycle();
}

EOathbringerMetallurgicalTier UAshenOathbringerLifecycleComponent::EvaluateWeaponLifecycle()
{
	EOathbringerMetallurgicalTier NewTier = EOathbringerMetallurgicalTier::BurdenedIron;

	if (UAshenSoulPublisher* Publisher = GetSoulPublisher())
	{
		const FSoulStateVector State = Publisher->GetSoulState();

		if (State.Corruption >= 0.70f)
		{
			// Tier 4: Devouring Nightsteel (Light-Absorbing Parasitic Horror)
			NewTier = EOathbringerMetallurgicalTier::DevouringNightsteel;
			EffectiveMass = 0.0f;
			ForwardPullImpulse = 400.0f;

			MaterialParameters.Roughness = 0.92f; // Light-absorbing velvet matte black
			MaterialParameters.Metallic = 0.95f;
			MaterialParameters.AnisotropyAngle = 0.80f; // Organic muscle veining
			MaterialParameters.LightAbsorptionRadius = 2.0f; // 2-inch ambient light dip
			MaterialParameters.ViscousSeepageNormalStrength = 0.65f; // Heat-haze bile vapor
			MaterialParameters.TapetumLucidumRetroreflection = 1.0f; // Wolf pommel eye shine
			MaterialParameters.EmissiveIntensity = 0.0f; // Zero Neon Law

			AcousticProfile.AirHissFrequency = 45.0f; // Sub-bass vacuum
			AcousticProfile.FoleyGrindIntensity = 0.10f;
			AcousticProfile.SilverChimeDecaySeconds = 0.0f;
			AcousticProfile.VacuumSuctionVolume = 0.85f;
			AcousticProfile.bDeadAcousticIsolation = false;
		}
		else if (State.Resolve >= 0.90f)
		{
			// Tier 5: Cold Monolith (Monolithic Obsidian-Steel / Absolute Stillness)
			NewTier = EOathbringerMetallurgicalTier::ColdMonolith;
			EffectiveMass = 35.0f; // Impossibly fine balance
			ForwardPullImpulse = 0.0f;

			MaterialParameters.Roughness = 0.05f; // Flawless surgical 2D edge
			MaterialParameters.Metallic = 1.0f;
			MaterialParameters.AnisotropyAngle = 0.0f;
			MaterialParameters.LightAbsorptionRadius = 0.0f;
			MaterialParameters.ViscousSeepageNormalStrength = 0.0f;
			MaterialParameters.TapetumLucidumRetroreflection = 0.0f;
			MaterialParameters.EmissiveIntensity = 0.0f; // Zero Neon Law

			AcousticProfile.AirHissFrequency = 0.0f;
			AcousticProfile.FoleyGrindIntensity = 0.0f;
			AcousticProfile.SilverChimeDecaySeconds = 0.0f;
			AcousticProfile.VacuumSuctionVolume = 0.0f;
			AcousticProfile.bDeadAcousticIsolation = true; // Complete swing silence
		}
		else if (State.Resolve >= 0.70f)
		{
			// Tier 3: The Scribed Vow (Cold Silver Inlays Catching Real Light)
			NewTier = EOathbringerMetallurgicalTier::ScribedVow;
			EffectiveMass = 50.0f;
			ForwardPullImpulse = 0.0f;

			MaterialParameters.Roughness = 0.15f; // Mirror-honed Damascus
			MaterialParameters.Metallic = 0.98f;
			MaterialParameters.AnisotropyAngle = 0.45f;
			MaterialParameters.LightAbsorptionRadius = 0.0f;
			MaterialParameters.ViscousSeepageNormalStrength = 0.0f;
			MaterialParameters.TapetumLucidumRetroreflection = 0.0f;
			MaterialParameters.EmissiveIntensity = 0.0f; // Zero Neon Law: Reflects ambient light

			AcousticProfile.AirHissFrequency = 2400.0f;
			AcousticProfile.FoleyGrindIntensity = 0.20f;
			AcousticProfile.SilverChimeDecaySeconds = 2.4f; // 528 Hz bell chime
			AcousticProfile.VacuumSuctionVolume = 0.0f;
			AcousticProfile.bDeadAcousticIsolation = false;
		}
		else if (State.Resolve >= 0.35f)
		{
			// Tier 2: Honed Damascus (Disciplined Folded Steel)
			NewTier = EOathbringerMetallurgicalTier::HonedDamascus;
			EffectiveMass = 85.0f;
			ForwardPullImpulse = 0.0f;

			MaterialParameters.Roughness = 0.35f;
			MaterialParameters.Metallic = 0.98f;
			MaterialParameters.AnisotropyAngle = 0.45f;
			MaterialParameters.LightAbsorptionRadius = 0.0f;
			MaterialParameters.ViscousSeepageNormalStrength = 0.0f;
			MaterialParameters.TapetumLucidumRetroreflection = 0.0f;
			MaterialParameters.EmissiveIntensity = 0.0f;

			AcousticProfile.AirHissFrequency = 2400.0f;
			AcousticProfile.FoleyGrindIntensity = 0.40f;
			AcousticProfile.SilverChimeDecaySeconds = 0.0f;
			AcousticProfile.VacuumSuctionVolume = 0.0f;
			AcousticProfile.bDeadAcousticIsolation = false;
		}
		else
		{
			// Tier 1: Burdened Iron (Neglected Trauma)
			NewTier = EOathbringerMetallurgicalTier::BurdenedIron;
			EffectiveMass = 120.0f;
			ForwardPullImpulse = 0.0f;

			MaterialParameters.Roughness = 0.65f;
			MaterialParameters.Metallic = 0.95f;
			MaterialParameters.AnisotropyAngle = 0.20f;
			MaterialParameters.LightAbsorptionRadius = 0.0f;
			MaterialParameters.ViscousSeepageNormalStrength = 0.0f;
			MaterialParameters.TapetumLucidumRetroreflection = 0.0f;
			MaterialParameters.EmissiveIntensity = 0.0f;

			AcousticProfile.AirHissFrequency = 1200.0f;
			AcousticProfile.FoleyGrindIntensity = 0.80f;
			AcousticProfile.SilverChimeDecaySeconds = 0.0f;
			AcousticProfile.VacuumSuctionVolume = 0.0f;
			AcousticProfile.bDeadAcousticIsolation = false;
		}
	}

	if (CurrentTier != NewTier)
	{
		CurrentTier = NewTier;
		OnMetallurgyChanged.Broadcast(CurrentTier, EffectiveMass, MaterialParameters, AcousticProfile);
		UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerLifecycleComponent: Metallurgical Tier [%d] (Mass: %.1fkg, Roughness: %.2f, LightAbsorb: %.1f, Silence: %d)."),
			(int32)CurrentTier, EffectiveMass, MaterialParameters.Roughness, MaterialParameters.LightAbsorptionRadius, AcousticProfile.bDeadAcousticIsolation ? 1 : 0);
	}

	return CurrentTier;
}

bool UAshenOathbringerLifecycleComponent::InscribeMemoryEchoToGuardSocket(
	EOathbringerMartialStance Guard,
	FName MemoryEchoID)
{
	if (MemoryEchoID.IsNone()) return false;

	GuardSocketMap.Add(Guard, MemoryEchoID);
	OnGuardSocketInscribed.Broadcast(Guard, MemoryEchoID);

	UE_LOG(LogTemp, Log, TEXT("UAshenOathbringerLifecycleComponent: Inscribed Echo '%s' to Guard Socket [%d]."),
		*MemoryEchoID.ToString(), (int32)Guard);

	return true;
}

FName UAshenOathbringerLifecycleComponent::GetSocketInscribedEcho(EOathbringerMartialStance Guard) const
{
	if (const FName* Found = GuardSocketMap.Find(Guard))
	{
		return *Found;
	}
	return NAME_None;
}

UAshenSoulPublisher* UAshenOathbringerLifecycleComponent::GetSoulPublisher() const
{
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			return GI->GetSubsystem<UAshenSoulPublisher>();
		}
	}
	return nullptr;
}
