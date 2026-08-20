// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenTriangleContainmentPrismActor.h"

AAshenTriangleContainmentPrismActor::AAshenTriangleContainmentPrismActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAshenTriangleContainmentPrismActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("AAshenTriangleContainmentPrismActor: Hard-light triangular prism containment boundary formed (Radius: %.0fuu)."), PrismRadius);
}

void AAshenTriangleContainmentPrismActor::ImplodeContainmentPrism()
{
	bIsPrismCollapsed = true;
	UE_LOG(LogTemp, Warning, TEXT("AAshenTriangleContainmentPrismActor: NULL-ZONE COLLAPSE! Hard-light prism imploded crushing all contained hostiles."));
	Destroy();
}
