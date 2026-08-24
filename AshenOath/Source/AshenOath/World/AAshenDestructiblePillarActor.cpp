// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenDestructiblePillarActor.h"
#include "Components/BoxComponent.h"

AAshenDestructiblePillarActor::AAshenDestructiblePillarActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	PillarMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PillarMesh"));
	PillarMesh->SetupAttachment(RootComponent);

	NavmeshObstacleBounds = CreateDefaultSubobject<UBoxComponent>(TEXT("NavmeshObstacleBounds"));
	NavmeshObstacleBounds->SetupAttachment(RootComponent);
	NavmeshObstacleBounds->SetBoxExtent(FVector(100.0f, 100.0f, 250.0f));

	MaterialType = EStructuralMaterialType::GraniteStone;
	CurrentSeverity = EChaosFractureSeverity::IntactSolid;
	StructuralHealthJoules = 6000.0f;
}

void AAshenDestructiblePillarActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenDestructiblePillarActor::ApplyStructuralImpact(float ImpactJoules)
{
	StructuralHealthJoules -= ImpactJoules;

	if (StructuralHealthJoules <= 0.0f)
	{
		CurrentSeverity = EChaosFractureSeverity::TotalDemolition;
	}
	else if (StructuralHealthJoules <= 2500.0f)
	{
		CurrentSeverity = EChaosFractureSeverity::PartialCollapse;
	}
	else if (StructuralHealthJoules <= 4500.0f)
	{
		CurrentSeverity = EChaosFractureSeverity::SurfaceFissure;
	}
}
