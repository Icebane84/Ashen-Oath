// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "AI/AshenCompanionSynergyPositioningDirector.h"

UAshenCompanionSynergyPositioningDirector::UAshenCompanionSynergyPositioningDirector()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenCompanionSynergyPositioningDirector::BeginPlay()
{
	Super::BeginPlay();
}

float UAshenCompanionSynergyPositioningDirector::EvaluateCompanionProximitySynergy(AActor* CompanionActor)
{
	if (!CompanionActor) return 0.0f;
	UE_LOG(LogTemp, Log, TEXT("UAshenCompanionSynergyPositioningDirector: Evaluated proximity synergy for companion %s"), *CompanionActor->GetName());
	return 1.0f;
}
