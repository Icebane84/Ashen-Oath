// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenGarrettPincerAttackFormationAdapterComponent.h"

UAshenGarrettPincerAttackFormationAdapterComponent::UAshenGarrettPincerAttackFormationAdapterComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FVector UAshenGarrettPincerAttackFormationAdapterComponent::CalculatePincerFlankLocation(const FVector& TargetLocation, const FVector& KaelenLocation)
{
	FVector DirectVector = (TargetLocation - KaelenLocation).GetSafeNormal();
	FVector FlankLocation = TargetLocation + (DirectVector * 200.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenGarrettPincerAttackFormationAdapterComponent: Calculated Garrett pincer flank location opposite Kaelen."));
	return FlankLocation;
}
