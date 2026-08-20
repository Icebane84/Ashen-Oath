// Copyright Phoenix Protocol. All rights reserved.

#include "AshenWeapon_Oathbringer.h"
#include "Components/PointLightComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_SanityComponent.h"
#include "AshenOathCharacter.h"
#include "AshenGameSettings.h"
#include "Engine/World.h"

AAshenWeapon_Oathbringer::AAshenWeapon_Oathbringer()
{
	PrimaryActorTick.bCanEverTick = true;

	EmissionLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("EmissionLight"));
	EmissionLight->SetupAttachment(GetWeaponMesh());
	EmissionLight->SetIntensity(500.0f);

	PureColor = FLinearColor(0.0f, 1.0f, 0.84f);
	CorruptColor = FLinearColor(0.545f, 0.0f, 0.0f);
	CorruptionThreshold = 0.8f;
	MaxScaleMultiplier = 1.7f;
	GlowColorParamName = TEXT("GlowColor");
	GlowIntensityParamName = TEXT("GlowIntensity");
	BaseScale = FVector::OneVector;
	CurrentCorruption = 0.0f;
}

void AAshenWeapon_Oathbringer::BeginPlay()
{
	Super::BeginPlay();

	// Load configuration-driven settings
	if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
	{
		PureColor = Settings->OathbringerPureColor;
		CorruptColor = Settings->OathbringerCorruptColor;
		CorruptionThreshold = Settings->OathbringerCorruptionThreshold;
		if (EmissionLight)
		{
			EmissionLight->SetIntensity(Settings->OathbringerLightIntensity);
		}
	}

	if (GetWeaponMesh())
	{
		BaseScale = GetWeaponMesh()->GetRelativeScale3D();
		WeaponMID = GetWeaponMesh()->CreateAndSetMaterialInstanceDynamic(0);
	}
}

void AAshenWeapon_Oathbringer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AActor* Wielder = GetOwner();
	if (!Wielder)
	{
		Wielder = GetAttachParentActor();
	}

	// 1. Calculate corruption from wielder's dynamic state or sanity fallback
	if (AAshenOathCharacter* CharacterWielder = Cast<AAshenOathCharacter>(Wielder))
	{
		CurrentCorruption = CharacterWielder->GetCorruptionAmount();
	}
	else if (Wielder && Wielder->Implements<UAshenCharacterInterface>())
	{
		if (UAshenOath_SanityComponent* Sanity = IAshenCharacterInterface::Execute_GetSanityComponent(Wielder))
		{
			float CurrentSanity = Sanity->GetCurrentSanity();
			float MaxSanity = Sanity->GetMaxSanity();
			if (MaxSanity > 0.0f)
			{
				CurrentCorruption = FMath::Clamp((MaxSanity - CurrentSanity) / MaxSanity, 0.0f, 1.0f);
			}
		}
	}

	// 2. Dynamic Weapon Scaling (Guts-style massive greatsword morph)
	if (GetWeaponMesh())
	{
		float WidthMin = 1.25f;
		float WidthMax = 2.7f;
		float LengthMin = 1.25f;
		float LengthMax = 1.8f;

		if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
		{
			WidthMin = Settings->OathbringerWidthMinScale;
			WidthMax = Settings->OathbringerWidthMaxScale;
			LengthMin = Settings->OathbringerLengthMinScale;
			LengthMax = Settings->OathbringerLengthMaxScale;
		}

		// Scale X/Y (width/thickness) and Z (length) non-uniformly
		float WidthFactor = FMath::Lerp(WidthMin, WidthMax, CurrentCorruption);
		float LengthFactor = FMath::Lerp(LengthMin, LengthMax, CurrentCorruption);
		
		FVector TargetScale = FVector(BaseScale.X * WidthFactor, BaseScale.Y * WidthFactor, BaseScale.Z * LengthFactor);
		GetWeaponMesh()->SetRelativeScale3D(TargetScale);
	}

	// 3. Dynamic Emission Pulsing and Color Lerping
	if (GetWorld())
	{
		float TimeSeconds = GetWorld()->GetTimeSeconds();
		
		// If corrupt, pulse faster and more erratically
		float PulseRate = (CurrentCorruption > CorruptionThreshold) ? 10.0f : 2.0f;
		float PulseVal = (FMath::Sin(TimeSeconds * PulseRate) + 1.0f) * 0.5f;

		float BaseIntensity = 500.0f;
		if (const UAshenGameSettings* Settings = GetDefault<UAshenGameSettings>())
		{
			BaseIntensity = Settings->OathbringerLightIntensity;
		}

		float TargetIntensity = 1.0f + (PulseVal * 1.5f);
		FLinearColor TargetColor = FLinearColor::LerpUsingHSV(PureColor, CorruptColor, CurrentCorruption);

		if (EmissionLight)
		{
			EmissionLight->SetLightColor(TargetColor);
			EmissionLight->SetIntensity(TargetIntensity * BaseIntensity * 2.0f); // Scale for point light component
		}

		if (WeaponMID)
		{
			WeaponMID->SetVectorParameterValue(GlowColorParamName, TargetColor);
			WeaponMID->SetScalarParameterValue(GlowIntensityParamName, TargetIntensity);
		}
	}
}
