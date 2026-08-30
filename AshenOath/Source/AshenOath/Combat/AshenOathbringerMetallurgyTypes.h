// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AshenOathbringerMetallurgyTypes.generated.h"

/**
 * EOathbringerMetallurgicalTier
 *
 * The 5 grounded metallurgical, physical, and psychological tiers of Oathbringer.
 * (METALLURGY-SPEC-102 / PRS-001-ENG-METAL-102)
 */
UENUM(BlueprintType)
enum class EOathbringerMetallurgicalTier : uint8
{
	BurdenedIron        UMETA(DisplayName = "Tier 1: Burdened Iron (Neglected Carbon Steel / 120kg)"),
	HonedDamascus       UMETA(DisplayName = "Tier 2: Honed Damascus (Disciplined Folded Steel / 85kg)"),
	ScribedVow          UMETA(DisplayName = "Tier 3: The Scribed Vow (Cold Silver Inlays / 50kg)"),
	DevouringNightsteel UMETA(DisplayName = "Tier 4: Devouring Nightsteel (Light-Absorbing Parasitic Horror / 0kg +400uu/s)"),
	ColdMonolith        UMETA(DisplayName = "Tier 5: Cold Monolith (Monolithic Obsidian-Steel / Absolute Silence / 35kg)")
};

/**
 * FOathbringerMaterialParameters
 *
 * Physical PBR parameters for rendering cold metal, surface finish, light absorption, and biological horror.
 */
USTRUCT(BlueprintType)
struct FOathbringerMaterialParameters
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metallurgy|PBR")
	float Roughness = 0.65f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metallurgy|PBR")
	float Metallic = 0.98f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metallurgy|PBR")
	float AnisotropyAngle = 0.45f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metallurgy|Horror")
	float LightAbsorptionRadius = 0.0f; // Ambient light absorption in inches (Tier 4)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metallurgy|Horror")
	float ViscousSeepageNormalStrength = 0.0f; // Seam heat-haze distortion

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metallurgy|Horror")
	float TapetumLucidumRetroreflection = 0.0f; // Wolf pommel eye shine scalar

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Metallurgy|AntiArcade")
	float EmissiveIntensity = 0.0f; // Zero Neon Law: Strictly 0.0f for Tiers 1, 2, 3, 5
};

/**
 * FOathbringerAcousticProfile
 *
 * Foley sound properties modeling physical mass, foley scrape, silver bell chime, and vacuum isolation.
 */
USTRUCT(BlueprintType)
struct FOathbringerAcousticProfile
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Acoustics|Foley")
	float AirHissFrequency = 1200.0f; // Hz

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Acoustics|Foley")
	float FoleyGrindIntensity = 0.80f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Acoustics|Resonance")
	float SilverChimeDecaySeconds = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Acoustics|Horror")
	float VacuumSuctionVolume = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Acoustics|Stillness")
	bool bDeadAcousticIsolation = false; // Tier 5 absolute swing silence
};
