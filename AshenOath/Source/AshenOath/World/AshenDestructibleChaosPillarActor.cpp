// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenDestructibleChaosPillarActor.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"

AAshenDestructibleChaosPillarActor::AAshenDestructibleChaosPillarActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	StructuralCollider = CreateDefaultSubobject<UCapsuleComponent>(TEXT("StructuralCollider"));
	StructuralCollider->SetupAttachment(RootComponent);
	StructuralCollider->InitCapsuleSize(60.0f, 200.0f);

	PillarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillarMesh"));
	PillarMesh->SetupAttachment(RootComponent);

	MaxIntegrityJoules = 4500.0f;
	CurrentIntegrityJoules = 4500.0f;
	bIsFractured = false;
}

void AAshenDestructibleChaosPillarActor::BeginPlay()
{
	Super::BeginPlay();
	CurrentIntegrityJoules = MaxIntegrityJoules;
	bIsFractured = false;
}

EStructuralFractureTier AAshenDestructibleChaosPillarActor::ApplyKineticImpact(
	float KineticEnergyJoules,
	const FVector& ImpactPoint)
{
	CurrentIntegrityJoules = FMath::Max(0.0f, CurrentIntegrityJoules - KineticEnergyJoules);

	if (CurrentIntegrityJoules <= 0.0f || KineticEnergyJoules >= MaxIntegrityJoules)
	{
		bIsFractured = true;
		return EStructuralFractureTier::CatastrophicCleave;
	}

	if (KineticEnergyJoules >= 1500.0f)
	{
		return EStructuralFractureTier::StructuralCrack;
	}

	return EStructuralFractureTier::SurfaceChipping;
}
