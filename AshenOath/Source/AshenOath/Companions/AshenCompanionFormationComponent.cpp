// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AshenCompanionFormationComponent.h"

UAshenCompanionFormationComponent::UAshenCompanionFormationComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	AssignedRole = EAshenFormationRole::FlankSupport;
	FormationDistance = 250.0f;
}

void UAshenCompanionFormationComponent::BeginPlay()
{
	Super::BeginPlay();
}

FVector UAshenCompanionFormationComponent::CalculateFormationOffset(EAshenFormationRole Role, FVector PlayerLocation, FVector PlayerForwardVector)
{
	FVector RightVector = FVector::CrossProduct(FVector::UpVector, PlayerForwardVector).GetSafeNormal();
	FVector TargetLoc = PlayerLocation;

	switch (Role)
	{
	case EAshenFormationRole::VanguardFront:
		TargetLoc += (PlayerForwardVector * FormationDistance) + (RightVector * 100.0f);
		break;
	case EAshenFormationRole::FlankSupport:
		TargetLoc += (RightVector * FormationDistance) - (PlayerForwardVector * 50.0f);
		break;
	case EAshenFormationRole::RearGuard:
		TargetLoc -= (PlayerForwardVector * FormationDistance);
		break;
	}

	OnFormationOffsetUpdated.Broadcast(Role, TargetLoc);
	return TargetLoc;
}
