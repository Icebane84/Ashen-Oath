// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AAshenSeveranceGibWorldActor.h"
#include "Components/StaticMeshComponent.h"

AAshenSeveranceGibWorldActor::AAshenSeveranceGibWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	GibMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GibMeshComponent"));
	RootComponent = GibMeshComponent;

	GibMeshComponent->SetSimulatePhysics(true);
	GibMeshComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GibMeshComponent->SetCollisionProfileName(TEXT("Ragdoll"));

	BoneType = ESeveranceBoneTarget::None;
	GibLifespanSeconds = 20.0f;
}

void AAshenSeveranceGibWorldActor::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan(GibLifespanSeconds);
}

void AAshenSeveranceGibWorldActor::InitializeGib(
	ESeveranceBoneTarget SeveredBone,
	const FVector& Impulse)
{
	BoneType = SeveredBone;

	if (GibMeshComponent && GibMeshComponent->IsSimulatingPhysics())
	{
		GibMeshComponent->AddImpulse(Impulse, NAME_None, true);
	}
}
