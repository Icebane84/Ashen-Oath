// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenSomaticResonanceTetherActor.h"
#include "Components/SplineComponent.h"
#include "Components/AudioComponent.h"

AAshenSomaticResonanceTetherActor::AAshenSomaticResonanceTetherActor()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	TetherSpline = CreateDefaultSubobject<USplineComponent>(TEXT("TetherSpline"));
	TetherSpline->SetupAttachment(RootComponent);

	ResonanceAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("ResonanceAudio"));
	ResonanceAudio->SetupAttachment(RootComponent);
	ResonanceAudio->bAutoActivate = false;

	MaxTetherDistance = 1000.0f;
	CurrentResonanceGlow = 0.0f;
	TargetGlow = 0.0f;
	bTetherActive = false;
}

void AAshenSomaticResonanceTetherActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CurrentResonanceGlow = FMath::FInterpTo(CurrentResonanceGlow, TargetGlow, DeltaTime, 4.0f);
}

void AAshenSomaticResonanceTetherActor::UpdateTetherEndpoints(
	const FVector& KaelenLocation,
	const FVector& CompanionLocation,
	float RelationalFlow)
{
	if (!TetherSpline)
	{
		return;
	}

	const float Distance = FVector::Dist(KaelenLocation, CompanionLocation);
	if (Distance > MaxTetherDistance)
	{
		SetTetherActive(false);
		return;
	}

	TetherSpline->ClearSplinePoints();
	TetherSpline->AddSplinePoint(KaelenLocation, ESplineCoordinateSpace::World);
	
	const FVector MidPoint = (KaelenLocation + CompanionLocation) * 0.5f + FVector(0.0f, 0.0f, 50.0f);
	TetherSpline->AddSplinePoint(MidPoint, ESplineCoordinateSpace::World);
	
	TetherSpline->AddSplinePoint(CompanionLocation, ESplineCoordinateSpace::World);
	TetherSpline->UpdateSpline();

	TargetGlow = FMath::Clamp(RelationalFlow, 0.0f, 1.0f);
	if (RelationalFlow >= 0.75f && !bTetherActive)
	{
		SetTetherActive(true);
	}
	else if (RelationalFlow < 0.75f && bTetherActive)
	{
		SetTetherActive(false);
	}
}

void AAshenSomaticResonanceTetherActor::SetTetherActive(bool bActive, float FadeDuration)
{
	bTetherActive = bActive;
	TargetGlow = bActive ? 1.0f : 0.0f;

	if (ResonanceAudio)
	{
		if (bActive && !ResonanceAudio->IsPlaying())
		{
			ResonanceAudio->Play();
		}
		else if (!bActive && ResonanceAudio->IsPlaying())
		{
			ResonanceAudio->FadeOut(FadeDuration, 0.0f);
		}
	}
}
