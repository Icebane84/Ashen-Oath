// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "UI/AshenParchmentDynamicMaterialAdapter.h"

UAshenParchmentDynamicMaterialAdapter::UAshenParchmentDynamicMaterialAdapter()
{
	PrimaryComponentTick.bCanEverTick = true;
	MaxJitterIntensity = 0.15f;
	CurrentJitterIntensity = 0.0f;
	CurrentInkBleed = 0.0f;
}

void UAshenParchmentDynamicMaterialAdapter::TickComponent(
	float DeltaTime,
	ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAshenParchmentDynamicMaterialAdapter::UpdateParchmentShader(float IntegrationDebt, float Corruption)
{
	CurrentJitterIntensity = FMath::Clamp(IntegrationDebt * MaxJitterIntensity, 0.0f, MaxJitterIntensity);
	CurrentInkBleed = FMath::Clamp((IntegrationDebt * 0.5f) + (Corruption * 0.5f), 0.0f, 1.0f);
}

float UAshenParchmentDynamicMaterialAdapter::CalculateVertexJitterOffset(float TimeSeconds) const
{
	return FMath::Sin(TimeSeconds * 20.0f) * CurrentJitterIntensity;
}
