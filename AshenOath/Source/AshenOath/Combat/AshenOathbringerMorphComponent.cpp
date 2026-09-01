// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Combat/AshenOathbringerMorphComponent.h"
#include "Components/MeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Engine/World.h"
#include "Engine/GameInstance.h"

UAshenOathbringerMorphComponent::UAshenOathbringerMorphComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	CurrentTier = EOathbringerMetallurgicalTier::BurdenedIron;
}

void UAshenOathbringerMorphComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register with SSoT Publisher
	if (const UWorld* World = GetWorld())
	{
		if (const UGameInstance* GI = World->GetGameInstance())
		{
			if (UAshenSoulPublisher* Publisher = GI->GetSubsystem<UAshenSoulPublisher>())
			{
				TScriptInterface<IAshenStateConsumer> ConsumerInterface;
				ConsumerInterface.SetObject(this);
				ConsumerInterface.SetInterface(Cast<IAshenStateConsumer>(this));
				Publisher->RegisterConsumer(ConsumerInterface);

				// Apply initial snapshot
				const FAshenStateSnapshot& Snapshot = Publisher->GetAuthoritativeSnapshot();
				OnStateSnapshotCommitted_Implementation(Snapshot);
			}
		}
	}
}

void UAshenOathbringerMorphComponent::SetTargetMesh(UMeshComponent* InMesh)
{
	TargetMeshComponent = InMesh;
	if (TargetMeshComponent)
	{
		DynamicMaterial = TargetMeshComponent->CreateDynamicMaterialInstance(0);
		UpdateMaterialShaderParameters();
	}
}

void UAshenOathbringerMorphComponent::OnStateSnapshotCommitted_Implementation(const FAshenStateSnapshot& Snapshot)
{
	// Derive target tier from authoritative snapshot
	EOathbringerMetallurgicalTier TargetTier = EOathbringerMetallurgicalTier::BurdenedIron;

	if ((Snapshot.Resolve >= 0.90f || Snapshot.Corruption >= 0.90f) && Snapshot.IntegrationDebt <= 0.05f)
	{
		TargetTier = EOathbringerMetallurgicalTier::ColdMonolith;
	}
	else if (Snapshot.Corruption >= 0.60f)
	{
		TargetTier = EOathbringerMetallurgicalTier::DevouringNightsteel;
	}
	else if (Snapshot.Resolve >= 0.60f)
	{
		TargetTier = EOathbringerMetallurgicalTier::ScribedVow;
	}
	else if (Snapshot.IntegrationDebt <= 0.20f)
	{
		TargetTier = EOathbringerMetallurgicalTier::HonedDamascus;
	}

	ApplyMetallurgyMorph(TargetTier, Snapshot.Resolve, Snapshot.Corruption, Snapshot.IntegrationDebt);
}

void UAshenOathbringerMorphComponent::ApplyMetallurgyMorph(
	EOathbringerMetallurgicalTier TargetTier,
	float InResolve,
	float InCorruption,
	float InDebt)
{
	CurrentTier = TargetTier;

	// Reset parameters according to Anti-Arcade Law (Zero RGB Neon)
	CurrentMaterialParams = FOathbringerMaterialParameters();
	CurrentAcousticProfile = FOathbringerAcousticProfile();

	switch (CurrentTier)
	{
	case EOathbringerMetallurgicalTier::BurdenedIron:
		CurrentMaterialParams.Roughness = 0.85f;
		CurrentMaterialParams.Metallic = 0.60f;
		CurrentMaterialParams.EmissiveIntensity = 0.0f; // Absolute zero neon
		CurrentMaterialParams.LightAbsorptionRadius = 0.0f;
		CurrentMaterialParams.TapetumLucidumRetroreflection = 0.0f;

		CurrentAcousticProfile.FoleyGrindIntensity = 1.0f;
		CurrentAcousticProfile.AirHissFrequency = 0.0f;
		CurrentAcousticProfile.bDeadAcousticIsolation = false;
		break;

	case EOathbringerMetallurgicalTier::HonedDamascus:
		CurrentMaterialParams.Roughness = 0.40f;
		CurrentMaterialParams.Metallic = 0.90f;
		CurrentMaterialParams.EmissiveIntensity = 0.0f;
		CurrentMaterialParams.LightAbsorptionRadius = 0.0f;
		CurrentMaterialParams.TapetumLucidumRetroreflection = 0.0f;

		CurrentAcousticProfile.FoleyGrindIntensity = 0.40f;
		CurrentAcousticProfile.AirHissFrequency = 2400.0f;
		CurrentAcousticProfile.bDeadAcousticIsolation = false;
		break;

	case EOathbringerMetallurgicalTier::ScribedVow:
		CurrentMaterialParams.Roughness = 0.20f;
		CurrentMaterialParams.Metallic = 0.95f;
		CurrentMaterialParams.EmissiveIntensity = 0.0f; // Reflects ambient light, zero neon
		CurrentMaterialParams.LightAbsorptionRadius = 0.0f;
		CurrentMaterialParams.TapetumLucidumRetroreflection = 0.0f;

		CurrentAcousticProfile.FoleyGrindIntensity = 0.20f;
		CurrentAcousticProfile.AirHissFrequency = 528.0f; // 528 Hz Harmonic Chime
		CurrentAcousticProfile.bDeadAcousticIsolation = false;
		break;

	case EOathbringerMetallurgicalTier::DevouringNightsteel:
		CurrentMaterialParams.Roughness = 0.95f;
		CurrentMaterialParams.Metallic = 0.80f;
		CurrentMaterialParams.EmissiveIntensity = 0.0f;
		CurrentMaterialParams.LightAbsorptionRadius = 2.0f; // 2.0-inch light absorption envelope
		CurrentMaterialParams.TapetumLucidumRetroreflection = 1.0f; // Tapetum Lucidum retroreflection

		CurrentAcousticProfile.FoleyGrindIntensity = 0.10f;
		CurrentAcousticProfile.AirHissFrequency = 110.0f; // Sub-bass vacuum drone
		CurrentAcousticProfile.bDeadAcousticIsolation = false;
		break;

	case EOathbringerMetallurgicalTier::ColdMonolith:
		CurrentMaterialParams.Roughness = 0.05f;
		CurrentMaterialParams.Metallic = 1.0f;
		CurrentMaterialParams.EmissiveIntensity = 0.0f;
		CurrentMaterialParams.LightAbsorptionRadius = 0.5f;
		CurrentMaterialParams.TapetumLucidumRetroreflection = 0.5f;

		CurrentAcousticProfile.FoleyGrindIntensity = 0.0f;
		CurrentAcousticProfile.AirHissFrequency = 0.0f;
		CurrentAcousticProfile.bDeadAcousticIsolation = true; // Absolute Swing Silence
		break;
	}

	UpdateMaterialShaderParameters();

	if (OnMetallurgyTierMorphed.IsBound())
	{
		OnMetallurgyTierMorphed.Broadcast(CurrentTier);
	}
}

void UAshenOathbringerMorphComponent::UpdateMaterialShaderParameters()
{
	if (!DynamicMaterial)
	{
		return;
	}

	DynamicMaterial->SetScalarParameterValue(FName("Roughness"), CurrentMaterialParams.Roughness);
	DynamicMaterial->SetScalarParameterValue(FName("Metallic"), CurrentMaterialParams.Metallic);
	DynamicMaterial->SetScalarParameterValue(FName("EmissiveIntensity"), CurrentMaterialParams.EmissiveIntensity);
	DynamicMaterial->SetScalarParameterValue(FName("LightAbsorptionRadius"), CurrentMaterialParams.LightAbsorptionRadius);
	DynamicMaterial->SetScalarParameterValue(FName("TapetumLucidumRetroreflection"), CurrentMaterialParams.TapetumLucidumRetroreflection);
}
