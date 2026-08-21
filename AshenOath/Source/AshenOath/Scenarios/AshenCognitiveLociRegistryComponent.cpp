// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#include "Scenarios/AshenCognitiveLociRegistryComponent.h"

UAshenCognitiveLociRegistryComponent::UAshenCognitiveLociRegistryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

FText UAshenCognitiveLociRegistryComponent::GetLocusDescription(const FName& LocusId) const
{
	if (LocusId == FName(TEXT("Locus_BruisedSky")))
	{
		return FText::FromString(TEXT("Cognitive Locus: 'The Bruised Sore Sky' — A sky of purple rot that tests perception."));
	}
	else if (LocusId == FName(TEXT("Locus_GarrettsGaze")))
	{
		return FText::FromString(TEXT("Cognitive Locus: 'Garrett's Anchor' — If his eyes do not follow the shadow, it does not exist."));
	}

	return FText::FromString(TEXT("Cognitive Locus: Memory trace anchored in the mindscape."));
}
