// Copyright Phoenix Protocol. All rights reserved.
#include "AshenSanityPostProcessComponent.h"
#include "Camera/CameraComponent.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "AshenCharacterInterface.h"
#include "AshenOath_SanityComponent.h"
#include "GameFramework/Actor.h"

UAshenSanityPostProcessComponent::UAshenSanityPostProcessComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	DistortionParamName = TEXT("SanityDistortionIntensity");
	DesaturationParamName = TEXT("DesaturationFactor");
	InterpolationSpeed = 3.0f;
	CurrentDistortion = 0.0f;
	CurrentDesaturation = 0.0f;
}

void UAshenSanityPostProcessComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (!Owner) return;

	// 1. Cache Follow Camera reference
	CachedCameraComponent = Owner->FindComponentByClass<UCameraComponent>();

	// 2. Cache Sanity Component via character interface
	if (Owner->Implements<UAshenCharacterInterface>())
	{
		CachedSanityComponent = IAshenCharacterInterface::Execute_GetSanityComponent(Owner);
	}

	// 3. Instantiate and attach Dynamic Material Instance to Camera Post-Process settings
	if (OverlayMaterialTemplate && CachedCameraComponent.IsValid())
	{
		DynamicPostProcessMID = UMaterialInstanceDynamic::Create(OverlayMaterialTemplate, this);
		if (DynamicPostProcessMID)
		{
			FWeightedBlendable Blendable(1.0f, DynamicPostProcessMID);
			CachedCameraComponent->PostProcessSettings.WeightedBlendables.Array.Add(Blendable);
		}
	}
}

void UAshenSanityPostProcessComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!DynamicPostProcessMID || !CachedSanityComponent.IsValid()) return;

	UAshenOath_SanityComponent* Sanity = CachedSanityComponent.Get();
	const float CurrentSanityVal = Sanity->GetCurrentSanity();
	const float MaxSanityVal = Sanity->GetMaxSanity();

	if (MaxSanityVal <= 0.0f) return;

	// Calculate instability ratio [0.0 = full sanity, 1.0 = zero sanity]
	const float InstabilityRatio = FMath::Clamp((MaxSanityVal - CurrentSanityVal) / MaxSanityVal, 0.0f, 1.0f);

	// Calculate targets
	const float TargetDistortion = InstabilityRatio * 0.85f;
	const float TargetDesaturation = InstabilityRatio * 0.60f;

	// Smooth linear interpolation to prevent jarring visual snapping
	CurrentDistortion = FMath::FInterpTo(CurrentDistortion, TargetDistortion, DeltaTime, InterpolationSpeed);
	CurrentDesaturation = FMath::FInterpTo(CurrentDesaturation, TargetDesaturation, DeltaTime, InterpolationSpeed);

	// Push values to shader material parameters
	DynamicPostProcessMID->SetScalarParameterValue(DistortionParamName, CurrentDistortion);
	DynamicPostProcessMID->SetScalarParameterValue(DesaturationParamName, CurrentDesaturation);
}
