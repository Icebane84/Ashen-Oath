// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Companions/AshenGarrettLineSnareComponent.h"

UAshenGarrettLineSnareComponent::UAshenGarrettLineSnareComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenGarrettLineSnareComponent::BeginPlay() { Super::BeginPlay(); }

bool UAshenGarrettLineSnareComponent::ExecuteLineSnareVault(AActor* TargetActor)
{
	bTargetNeckExposed = true;
	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettLineSnareComponent: Garrett snared %s with alchemical line hook! Target armor coated in Burning Steel Oil."),
		TargetActor ? *TargetActor->GetName() : TEXT("Target"));
	return true;
}
