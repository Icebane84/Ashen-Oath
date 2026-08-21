// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "World/AshenGarrettPhysicalTrapWorldActor.h"
#include "Components/StaticMeshComponent.h"

AAshenGarrettPhysicalTrapWorldActor::AAshenGarrettPhysicalTrapWorldActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	RootComponent = SceneRoot;

	TrapMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("TrapMesh"));
	TrapMesh->SetupAttachment(RootComponent);
	TrapMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));

	TrapType = EGarrettTrapType::TensionWireSnare;
	DetonationRadiusCentimeters = 350.0f;
	bIsArmed = false;
	bHasDetonated = false;
}

void AAshenGarrettPhysicalTrapWorldActor::BeginPlay()
{
	Super::BeginPlay();
}

void AAshenGarrettPhysicalTrapWorldActor::ArmTrap(EGarrettTrapType InType, float InRadius)
{
	TrapType = InType;
	DetonationRadiusCentimeters = InRadius;
	bIsArmed = true;
	bHasDetonated = false;
}

void AAshenGarrettPhysicalTrapWorldActor::DetonateTrap()
{
	bIsArmed = false;
	bHasDetonated = true;
}
